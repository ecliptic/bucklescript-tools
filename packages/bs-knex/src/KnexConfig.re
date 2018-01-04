module Connection = {
  type t = {
    .
    "host": string,
    "user": string,
    "password": string,
    "database": string,
    "domain": Js.Nullable.t(string),
    "instanceName": Js.Nullable.t(string),
    "debug": Js.Nullable.t(Js.boolean),
    "requestTimeout": Js.Nullable.t(int)
  };
};

module Pool = {
  type t = {
    .
    "name": Js.Nullable.t(string),
    "min": Js.Nullable.t(int),
    "max": Js.Nullable.t(int),
    "refreshIdle": Js.Nullable.t(Js.boolean),
    "idleTimeoutMillis": Js.Nullable.t(int),
    "reapIntervalMillis": Js.Nullable.t(int),
    "returnToHead": Js.Nullable.t(Js.boolean),
    "priorityRange": Js.Nullable.t(int),
    "log": Js.Nullable.t(Js.boolean),
    /* generic-pool v3 configs */
    "maxWaitingClients": Js.Nullable.t(int),
    "testOnBorrow": Js.Nullable.t(Js.boolean),
    "acquireTimeoutMillis": Js.Nullable.t(int),
    "fifo": Js.Nullable.t(Js.boolean),
    "autostart": Js.Nullable.t(Js.boolean),
    "evictionRunIntervalMillis": Js.Nullable.t(int),
    "numTestsPerRun": Js.Nullable.t(int),
    "softIdleTimeoutMillis": Js.Nullable.t(int)
  };
  let make =
      (
        ~name=Js.Nullable.null,
        ~min=Js.Nullable.null,
        ~max=Js.Nullable.null,
        ~refreshIdle=Js.Nullable.null,
        ~idleTimeoutMillis=Js.Nullable.null,
        ~reapIntervalMillis=Js.Nullable.null,
        ~returnToHead=Js.Nullable.null,
        ~priorityRange=Js.Nullable.null,
        ~log=Js.Nullable.null,
        ~maxWaitingClients=Js.Nullable.null,
        ~testOnBorrow=Js.Nullable.null,
        ~acquireTimeoutMillis=Js.Nullable.null,
        ~fifo=Js.Nullable.null,
        ~autostart=Js.Nullable.null,
        ~evictionRunIntervalMillis=Js.Nullable.null,
        ~numTestsPerRun=Js.Nullable.null,
        ~softIdleTimeoutMillis=Js.Nullable.null,
        ()
      ) => {
    "name": name,
    "min": min,
    "max": max,
    "refreshIdle": refreshIdle,
    "idleTimeoutMillis": idleTimeoutMillis,
    "reapIntervalMillis": reapIntervalMillis,
    "returnToHead": returnToHead,
    "priorityRange": priorityRange,
    "log": log,
    "maxWaitingClients": maxWaitingClients,
    "testOnBorrow": testOnBorrow,
    "acquireTimeoutMillis": acquireTimeoutMillis,
    "fifo": fifo,
    "autostart": autostart,
    "evictionRunIntervalMillis": evictionRunIntervalMillis,
    "numTestsPerRun": numTestsPerRun,
    "softIdleTimeoutMillis": softIdleTimeoutMillis
  };
};

module Migrations = {
  type t = {
    .
    "database": Js.Nullable.t(string),
    "directory": Js.Nullable.t(string),
    "extension": Js.Nullable.t(string),
    "tableName": Js.Nullable.t(string),
    "disableTransactions": Js.Nullable.t(bool)
  };
  let make =
      (
        ~database=Js.Nullable.null,
        ~directory=Js.Nullable.null,
        ~extension=Js.Nullable.null,
        ~tableName=Js.Nullable.null,
        ~disableTransactions=Js.Nullable.null,
        ()
      )
      : t => {
    "database": database,
    "directory": directory,
    "extension": extension,
    "tableName": tableName,
    "disableTransactions": disableTransactions
  };
};

module Db = {
  type t = {
    .
    "driver": string,
    "user": Js.Nullable.t(string),
    "password": Js.Nullable.t(string),
    "host": Js.Nullable.t(string),
    "hosts": Js.Nullable.t(array({. "host": string, "port": Js.Nullable.t(string)})),
    "port": Js.Nullable.t(string),
    "database": Js.Nullable.t(string),
    "filename": Js.Nullable.t(string),
    "native": Js.Nullable.t(Js.boolean),
    "reconnect": Js.Nullable.t(Js.boolean)
  };
};

type seeds = {. "directory": Js.Nullable.t(string)};

type t = {
  .
  "debug": Js.Nullable.t(string),
  "client": Js.Nullable.t(string),
  "dialect": Js.Nullable.t(string),
  "version": Js.Nullable.t(string),
  "connection": Js.Nullable.t(Connection.t),
  "pool": Js.Nullable.t(Pool.t),
  "migrations": Js.Nullable.t(Migrations.t),
  "seeds": Js.Nullable.t(seeds),
  "acquireConnectionTimeout": Js.Nullable.t(int),
  "useNullAsDefault": Js.Nullable.t(bool),
  "searchPath": Js.Nullable.t(string)
};

let make =
    (
      ~debug=Js.Nullable.null,
      ~client=Js.Nullable.null,
      ~dialect=Js.Nullable.null,
      ~version=Js.Nullable.null,
      ~connection=Js.Nullable.null,
      ~pool=Js.Nullable.null,
      ~migrations=Js.Nullable.null,
      ~seeds=Js.Nullable.null,
      ~acquireConnectionTimeout=Js.Nullable.null,
      ~useNullAsDefault=Js.Nullable.null,
      ~searchPath=Js.Nullable.null,
      ()
    )
    : t => {
  "debug": debug,
  "client": client,
  "dialect": dialect,
  "version": version,
  "connection": connection,
  "pool": pool,
  "migrations": migrations,
  "seeds": seeds,
  "acquireConnectionTimeout": acquireConnectionTimeout,
  "useNullAsDefault": useNullAsDefault,
  "searchPath": searchPath
};
