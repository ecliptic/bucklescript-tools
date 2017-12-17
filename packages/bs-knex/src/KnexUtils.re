open Js.Promise;

let getEnvVar = (key, fallback) =>
  Js.Option.getWithDefault(fallback, Js.Dict.get(Node.Process.process##env, key));

let debug = Debug.make(getEnvVar("KNEX_DEBUG_PREFIX", "bs-knex"), "KnexUtils");

let debugExn = Debug.make(getEnvVar("KNEX_DEBUG_PREFIX", "bs-knex"), "KnexUtils:exn");

type host = {. "host": string, "port": Js.Nullable.t(string)};

type config = {
  .
  "driver": string,
  "user": Js.Nullable.t(string),
  "password": Js.Nullable.t(string),
  "host": Js.Nullable.t(string),
  "hosts": Js.Nullable.t(array(host)),
  "port": Js.Nullable.t(string),
  "database": Js.Nullable.t(string),
  "filename": Js.Nullable.t(string),
  "native": Js.Nullable.t(Js.boolean),
  "reconnect": Js.Nullable.t(Js.boolean)
};

[@bs.module] external parseDbUrl : string => config = "parse-database-url";

[@bs.new] external makeError : string => exn = "Error";

/* Database Exceptions */
/** Retrieve the "code" from a database exception */ [@bs.get]
external exnCode : Js.Promise.error => Js.Nullable.t(string) =
  "code";

/** Retrieve the "constraint" from a database exception */ [@bs.get]
external exnConstraint : Js.Promise.error => Js.Nullable.t(string) =
  "constraint";

/** Retrieve the "routine" from a database exception */ [@bs.get]
external exnRoutine : Js.Promise.error => Js.Nullable.t(string) =
  "routine";

let invalidTextRepresentation = "22P02";

let uniqueViolation = "23505";

/**
 * Safely converts an object to json by stringifying it and parsing the results.
 */
let objToJson = (obj: Js.t('a)) : Js.Json.t => {
  let str = Js.Json.stringifyAny(obj);
  /* parseExn should be safe because the string came from stringifyAny */
  switch str {
  | Some(str) => str |> Js.Json.parseExn
  | None => Js.Json.null
  }
};

/*
 * Pass-through error handlers - handles a specific error, letting all the rest flow through to the
 * next handler.
 */
/** Handles errors for the specified unique constraint */
let handleUniqueError = (~name: string, ~message: string, promise) =>
  promise
  |> catch(
       (exn) => {
         let continue = reject(Debug.toExn(exn));
         let codeOpt = exn |> exnCode |> Js.Nullable.to_opt;
         switch codeOpt {
         | Some(code) =>
           if (code === uniqueViolation) {
             let constraintOpt = exn |> exnConstraint |> Js.Nullable.to_opt;
             switch constraintOpt {
             | Some(constraintName) =>
               if (constraintName === name) {
                 reject(makeError(message))
               } else {
                 continue
               }
             | None => continue
             }
           } else {
             continue
           }
         | None => continue
         }
       }
     );

/*
 * Terminator error handler - handles all remaining unhandled DB errors
 */
/** Handle generic database errors */
let handleDbErrors = (promise) =>
  promise
  |> catch(
       (exn) => {
         let codeOpt = exn |> exnCode |> Js.Nullable.to_opt;
         switch codeOpt {
         | Some(code) =>
           if (code === uniqueViolation) {
             reject(makeError("A unique constraint was violated."))
           } else if (code === invalidTextRepresentation) {
             let routineOpt = exn |> exnRoutine |> Js.Nullable.to_opt;
             switch routineOpt {
             | Some(routine) =>
               if (routine === "string_to_uuid") {
                 reject(makeError("The database received an invalid format for a UUID"))
               } else {
                 reject(makeError("The database received an invalid text representation."))
               }
             | None => reject(makeError("The database received an invalid text representation."))
             }
           } else {
             debug("Unhandled error:");
             debugExn(exn);
             reject(makeError("A database error occurred."))
           }
         | None =>
           debug("Unhandled error:");
           debugExn(exn);
           reject(makeError("A database error occurred."))
         }
       }
     );

let decodeResults = (~decoder: Js.Json.t => 'a, results: array('row)) =>
  results |> Js.Array.map(objToJson) |> Js.Array.map(decoder) |> Js.Promise.resolve;

let rejectIfEmpty = (~decoder, ~error, results) =>
  switch results {
  | [||] => Js.Promise.reject(makeError(error))
  | results => decodeResults(~decoder, results)
  };

let pickFirst = (results) => Js.Promise.resolve(results[0]);
