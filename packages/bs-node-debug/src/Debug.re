[@bs.module] external debug : string => [@bs] ('a => unit) = "";

external toJsExn : Js.Promise.error => Js.Exn.t = "%identity";

external toExn : Js.Promise.error => exn = "%identity";

let make = (prefix: string, label: string) => {
  let log = debug(prefix ++ ":" ++ label);
  (message) => [@bs] log(message)
};
