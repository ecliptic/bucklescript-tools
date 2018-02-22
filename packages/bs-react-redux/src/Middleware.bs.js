'use strict';

var Curry = require("bs-platform/lib/js/curry.js");

function handleActors(actors, store, next, action) {
  var match_000 = store.dispatch;
  var match_001 = store.getState;
  var getState = match_001;
  var dispatch = match_000;
  var result = Curry._1(next, action);
  actors.forEach((function (actor) {
          var response = Curry._3(actor, action, dispatch, getState);
          if (response == null) {
            return /* () */0;
          } else {
            Curry._1(dispatch, response);
            return /* () */0;
          }
        }));
  return result;
}

exports.handleActors = handleActors;
/* No side effect */
