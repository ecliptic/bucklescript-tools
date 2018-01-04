'use strict';

var Debug = require("debug");

function make(prefix, label) {
  var log = Debug(prefix + ":" + label);
  return (function (message) {
      return log(message);
    });
}

exports.make = make;
/* debug Not a pure module */
