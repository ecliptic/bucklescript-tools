'use strict';


var Connection = /* module */[];

function make($staropt$star, $staropt$star$1, $staropt$star$2, $staropt$star$3, $staropt$star$4, $staropt$star$5, $staropt$star$6, $staropt$star$7, $staropt$star$8, $staropt$star$9, $staropt$star$10, $staropt$star$11, $staropt$star$12, $staropt$star$13, $staropt$star$14, $staropt$star$15, $staropt$star$16, _) {
  var name = $staropt$star ? $staropt$star[0] : null;
  var min = $staropt$star$1 ? $staropt$star$1[0] : null;
  var max = $staropt$star$2 ? $staropt$star$2[0] : null;
  var refreshIdle = $staropt$star$3 ? $staropt$star$3[0] : null;
  var idleTimeoutMillis = $staropt$star$4 ? $staropt$star$4[0] : null;
  var reapIntervalMillis = $staropt$star$5 ? $staropt$star$5[0] : null;
  var returnToHead = $staropt$star$6 ? $staropt$star$6[0] : null;
  var priorityRange = $staropt$star$7 ? $staropt$star$7[0] : null;
  var log = $staropt$star$8 ? $staropt$star$8[0] : null;
  var maxWaitingClients = $staropt$star$9 ? $staropt$star$9[0] : null;
  var testOnBorrow = $staropt$star$10 ? $staropt$star$10[0] : null;
  var acquireTimeoutMillis = $staropt$star$11 ? $staropt$star$11[0] : null;
  var fifo = $staropt$star$12 ? $staropt$star$12[0] : null;
  var autostart = $staropt$star$13 ? $staropt$star$13[0] : null;
  var evictionRunIntervalMillis = $staropt$star$14 ? $staropt$star$14[0] : null;
  var numTestsPerRun = $staropt$star$15 ? $staropt$star$15[0] : null;
  var softIdleTimeoutMillis = $staropt$star$16 ? $staropt$star$16[0] : null;
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

var Pool = /* module */[/* make */make];

function make$1($staropt$star, $staropt$star$1, $staropt$star$2, $staropt$star$3, $staropt$star$4, _) {
  var database = $staropt$star ? $staropt$star[0] : null;
  var directory = $staropt$star$1 ? $staropt$star$1[0] : null;
  var extension = $staropt$star$2 ? $staropt$star$2[0] : null;
  var tableName = $staropt$star$3 ? $staropt$star$3[0] : null;
  var disableTransactions = $staropt$star$4 ? $staropt$star$4[0] : null;
  return {
          database: database,
          directory: directory,
          extension: extension,
          tableName: tableName,
          disableTransactions: disableTransactions
        };
}

var Migrations = /* module */[/* make */make$1];

var Db = /* module */[];

function make$2($staropt$star, $staropt$star$1, $staropt$star$2, $staropt$star$3, $staropt$star$4, $staropt$star$5, $staropt$star$6, $staropt$star$7, $staropt$star$8, $staropt$star$9, $staropt$star$10, _) {
  var debug = $staropt$star ? $staropt$star[0] : null;
  var client = $staropt$star$1 ? $staropt$star$1[0] : null;
  var dialect = $staropt$star$2 ? $staropt$star$2[0] : null;
  var version = $staropt$star$3 ? $staropt$star$3[0] : null;
  var connection = $staropt$star$4 ? $staropt$star$4[0] : null;
  var pool = $staropt$star$5 ? $staropt$star$5[0] : null;
  var migrations = $staropt$star$6 ? $staropt$star$6[0] : null;
  var seeds = $staropt$star$7 ? $staropt$star$7[0] : null;
  var acquireConnectionTimeout = $staropt$star$8 ? $staropt$star$8[0] : null;
  var useNullAsDefault = $staropt$star$9 ? $staropt$star$9[0] : null;
  var searchPath = $staropt$star$10 ? $staropt$star$10[0] : null;
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
exports.make       = make$2;
/* No side effect */
