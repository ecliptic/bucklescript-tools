'use strict';


function make(host, $staropt$star, user, password, database, $staropt$star$1, $staropt$star$2, $staropt$star$3, $staropt$star$4, _) {
  var port = $staropt$star ? $staropt$star[0] : undefined;
  var domain = $staropt$star$1 ? $staropt$star$1[0] : undefined;
  var instanceName = $staropt$star$2 ? $staropt$star$2[0] : undefined;
  var debug = $staropt$star$3 ? $staropt$star$3[0] : undefined;
  var requestTimeout = $staropt$star$4 ? $staropt$star$4[0] : undefined;
  return {
          host: host,
          port: port,
          user: user,
          password: password,
          database: database,
          domain: domain,
          instanceName: instanceName,
          debug: debug,
          requestTimeout: requestTimeout
        };
}

var Connection = /* module */[/* make */make];

function make$1($staropt$star, $staropt$star$1, $staropt$star$2, $staropt$star$3, $staropt$star$4, $staropt$star$5, $staropt$star$6, $staropt$star$7, $staropt$star$8, $staropt$star$9, $staropt$star$10, $staropt$star$11, $staropt$star$12, $staropt$star$13, $staropt$star$14, $staropt$star$15, $staropt$star$16, _) {
  var name = $staropt$star ? $staropt$star[0] : undefined;
  var min = $staropt$star$1 ? $staropt$star$1[0] : undefined;
  var max = $staropt$star$2 ? $staropt$star$2[0] : undefined;
  var refreshIdle = $staropt$star$3 ? $staropt$star$3[0] : undefined;
  var idleTimeoutMillis = $staropt$star$4 ? $staropt$star$4[0] : undefined;
  var reapIntervalMillis = $staropt$star$5 ? $staropt$star$5[0] : undefined;
  var returnToHead = $staropt$star$6 ? $staropt$star$6[0] : undefined;
  var priorityRange = $staropt$star$7 ? $staropt$star$7[0] : undefined;
  var log = $staropt$star$8 ? $staropt$star$8[0] : undefined;
  var maxWaitingClients = $staropt$star$9 ? $staropt$star$9[0] : undefined;
  var testOnBorrow = $staropt$star$10 ? $staropt$star$10[0] : undefined;
  var acquireTimeoutMillis = $staropt$star$11 ? $staropt$star$11[0] : undefined;
  var fifo = $staropt$star$12 ? $staropt$star$12[0] : undefined;
  var autostart = $staropt$star$13 ? $staropt$star$13[0] : undefined;
  var evictionRunIntervalMillis = $staropt$star$14 ? $staropt$star$14[0] : undefined;
  var numTestsPerRun = $staropt$star$15 ? $staropt$star$15[0] : undefined;
  var softIdleTimeoutMillis = $staropt$star$16 ? $staropt$star$16[0] : undefined;
  return {
          name: name,
          min: min,
          max: max,
          refreshIdle: refreshIdle,
          idleTimeoutMillis: idleTimeoutMillis,
          reapIntervalMillis: reapIntervalMillis,
          returnToHead: returnToHead,
          priorityRange: priorityRange,
          log: log,
          maxWaitingClients: maxWaitingClients,
          testOnBorrow: testOnBorrow,
          acquireTimeoutMillis: acquireTimeoutMillis,
          fifo: fifo,
          autostart: autostart,
          evictionRunIntervalMillis: evictionRunIntervalMillis,
          numTestsPerRun: numTestsPerRun,
          softIdleTimeoutMillis: softIdleTimeoutMillis
        };
}

var Pool = /* module */[/* make */make$1];

function make$2($staropt$star, $staropt$star$1, $staropt$star$2, $staropt$star$3, $staropt$star$4, _) {
  var database = $staropt$star ? $staropt$star[0] : undefined;
  var directory = $staropt$star$1 ? $staropt$star$1[0] : undefined;
  var extension = $staropt$star$2 ? $staropt$star$2[0] : undefined;
  var tableName = $staropt$star$3 ? $staropt$star$3[0] : undefined;
  var disableTransactions = $staropt$star$4 ? $staropt$star$4[0] : undefined;
  return {
          database: database,
          directory: directory,
          extension: extension,
          tableName: tableName,
          disableTransactions: disableTransactions
        };
}

var Migrations = /* module */[/* make */make$2];

var Db = /* module */[];

function make$3($staropt$star, $staropt$star$1, $staropt$star$2, $staropt$star$3, $staropt$star$4, $staropt$star$5, $staropt$star$6, $staropt$star$7, $staropt$star$8, $staropt$star$9, $staropt$star$10, _) {
  var debug = $staropt$star ? $staropt$star[0] : undefined;
  var client = $staropt$star$1 ? $staropt$star$1[0] : undefined;
  var dialect = $staropt$star$2 ? $staropt$star$2[0] : undefined;
  var version = $staropt$star$3 ? $staropt$star$3[0] : undefined;
  var connection = $staropt$star$4 ? $staropt$star$4[0] : undefined;
  var pool = $staropt$star$5 ? $staropt$star$5[0] : undefined;
  var migrations = $staropt$star$6 ? $staropt$star$6[0] : undefined;
  var seeds = $staropt$star$7 ? $staropt$star$7[0] : undefined;
  var acquireConnectionTimeout = $staropt$star$8 ? $staropt$star$8[0] : undefined;
  var useNullAsDefault = $staropt$star$9 ? $staropt$star$9[0] : undefined;
  var searchPath = $staropt$star$10 ? $staropt$star$10[0] : undefined;
  return {
          debug: debug,
          client: client,
          dialect: dialect,
          version: version,
          connection: connection,
          pool: pool,
          migrations: migrations,
          seeds: seeds,
          acquireConnectionTimeout: acquireConnectionTimeout,
          useNullAsDefault: useNullAsDefault,
          searchPath: searchPath
        };
}

exports.Connection = Connection;
exports.Pool       = Pool;
exports.Migrations = Migrations;
exports.Db         = Db;
exports.make       = make$3;
/* No side effect */
