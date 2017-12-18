'use strict';

var Chalk = require("chalk");

function fromInt(level) {
  if (level > 3 || level < 0) {
    return /* None */0;
  } else {
    return level;
  }
}

function toInt(level) {
  return level;
}

var Level = /* module */[
  /* fromInt */fromInt,
  /* toInt */toInt
];

var level = fromInt(Chalk.level);

function rgb(r, g, b) {
  return Chalk.rgb(r, g, b);
}

function hsl(h, s, l) {
  return Chalk.hsl(h, s, l);
}

function hsv(h, s, v) {
  return Chalk.hsv(h, s, v);
}

function hwb(h, w, b) {
  return Chalk.hwb(h, w, b);
}

function bgRgb(r, g, b) {
  return Chalk.bgRgb(r, g, b);
}

function bgHsl(h, s, l) {
  return Chalk.bgHsl(h, s, l);
}

function bgHsv(h, s, v) {
  return Chalk.bgHsv(h, s, v);
}

function bgHwb(h, w, b) {
  return Chalk.bgHwb(h, w, b);
}

exports.Level = Level;
exports.level = level;
exports.rgb   = rgb;
exports.hsl   = hsl;
exports.hsv   = hsv;
exports.hwb   = hwb;
exports.bgRgb = bgRgb;
exports.bgHsl = bgHsl;
exports.bgHsv = bgHsv;
exports.bgHwb = bgHwb;
/* level Not a pure module */
