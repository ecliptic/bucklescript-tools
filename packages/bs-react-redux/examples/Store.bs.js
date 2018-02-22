'use strict';

var Redux      = require("redux");
var Middleware = require("../src/Middleware.bs.js");

function reducer(state, _) {
  return Object.assign({ }, Object.assign(state, {
                  isMenuOpen: 1 - state.isMenuOpen
                }));
}

var actors = /* array */[];

var Header = /* module */[
  /* reducer */reducer,
  /* actors */actors
];

var rootReducer = Redux.combineReducers({
      header: reducer
    });

function create() {
  return Redux.createStore(rootReducer, undefined, Redux.applyMiddleware((function (param, param$1, param$2) {
                    return Middleware.handleActors(actors, param, param$1, param$2);
                  })));
}

exports.Header      = Header;
exports.rootReducer = rootReducer;
exports.actors      = actors;
exports.create      = create;
/* rootReducer Not a pure module */
