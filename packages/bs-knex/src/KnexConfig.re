module Connection = {
  type t = {
    .
    "host": string,
    "port": Js.Nullable.t(string),
    "user": string,
    "password": string,
    "database": string,
    "domain": Js.Nullable.t(string),
    "instanceName": Js.Nullable.t(string),
    "debug": Js.Nullable.t(Js.boolean),
    "requestTimeout": Js.Nullable.t(int)
  };
  let make =
      (
        ~host,
        ~port=Js.Nullable.undefined,
        ~user,
        ~password,
        ~database,
        ~domain=Js.Nullable.undefined,
        ~instanceName=Js.Nullable.undefined,
        ~debug=Js.Nullable.undefined,
        ~requestTimeout=Js.Nullable.undefined,
        ()
      ) => {
    "host": host,
    "port": port,
    "user": user,
    "password": password,
    "database": database,
    "domain": domain,
    "instanceName": instanceName,
    "debug": debug,
    "requestTimeout": requestTimeout
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
        ~name=Js.Nullable.undefined,
        ~min=Js.Nullable.undefined,
        ~max=Js.Nullable.undefined,
        ~refreshIdle=Js.Nullable.undefined,
        ~idleTimeoutMillis=Js.Nullable.undefined,
        ~reapIntervalMillis=Js.Nullable.undefined,
        ~returnToHead=Js.Nullable.undefined,
        ~priorityRange=Js.Nullable.undefined,
        ~log=Js.Nullable.undefined,
        ~maxWaitingClients=Js.Nullable.undefined,
        ~testOnBorrow=Js.Nullable.undefined,
        ~acquireTimeoutMillis=Js.Nullable.undefined,
        ~fifo=Js.Nullable.undefined,
        ~autostart=Js.Nullable.undefined,
        ~evictionRunIntervalMillis=Js.Nullable.undefined,
        ~numTestsPerRun=Js.Nullable.undefined,
        ~softIdleTimeoutMillis=Js.Nullable.undefined,
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
        ~database=Js.Nullable.undefined,
        ~directory=Js.Nullable.undefined,
        ~extension=Js.Nullable.undefined,
        ~tableName=Js.Nullable.undefined,
        ~disableTransactions=Js.Nullable.undefined,
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
      ~debug=Js.Nullable.undefined,
      ~client=Js.Nullable.undefined,
      ~dialect=Js.Nullable.undefined,
      ~version=Js.Nullable.undefined,
      ~connection=Js.Nullable.undefined,
      ~pool=Js.Nullable.undefined,
      ~migrations=Js.Nullable.undefined,
      ~seeds=Js.Nullable.undefined,
      ~acquireConnectionTimeout=Js.Nullable.undefined,
      ~useNullAsDefault=Js.Nullable.undefined,
      ~searchPath=Js.Nullable.undefined,
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
