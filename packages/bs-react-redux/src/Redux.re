type reAction = ..;

type action('action) = {.. "_type": string, "reType": reAction} as 'action;

type actionCreator('action, 'b) = 'b => action('action);

type dispatch('action) = action('action) => action('action);

type reducer('action, 'state) = ('state, action('action)) => 'state;

type store('action, 'state) = {
  .
  "dispatch": [@bs.meth] dispatch('action), "getState": unit => 'state
};

type storeCreator('action, 'state) =
  (reducer('action, Js.Nullable.t('state)), 'state) => store('action, 'state);

type storeEnhancer('action, 'state) =
  storeCreator('action, 'state) => storeCreator('action, 'state);

type middlewareApi('action, 'state) = {
  .
  "dispatch": dispatch('action), "getState": unit => 'state
};

type middleware('action, 'state) =
  (middlewareApi('action, 'state), dispatch('action)) => dispatch('action);

module ReduxJs = {
  [@bs.module "redux"]
  external createStore :
    (
      ~reducer: reducer('action, 'state),
      ~preloadedState: 'state=?,
      ~enhancer: storeEnhancer('action, 'state)=?,
      unit
    ) =>
    store('action, 'state) =
    "";
  [@bs.module "redux"]
  external combineReducers : (~reducers: Js.t('reducers)) => reducer('action, 'state) =
    "";
  [@bs.module "redux"]
  external applyMiddleware : middleware('action, 'state) => storeEnhancer('action, 'state) =
    "";
  [@bs.module "redux"]
  external applyMiddleware2 :
    (middleware('action, 'state), middleware('action, 'state)) => storeEnhancer('action, 'state) =
    "applyMiddleware";
  [@bs.module "redux"]
  external applyMiddleware3 :
    (middleware('action, 'state), middleware('action, 'state), middleware('action, 'state)) =>
    storeEnhancer('action, 'state) =
    "applyMiddleware";
  [@bs.module "redux"]
  external applyMiddleware4 :
    (
      middleware('action, 'state),
      middleware('action, 'state),
      middleware('action, 'state),
      middleware('action, 'state)
    ) =>
    storeEnhancer('action, 'state) =
    "applyMiddleware";
  [@bs.module "redux"]
  external applyMiddleware5 :
    (
      middleware('action, 'state),
      middleware('action, 'state),
      middleware('action, 'state),
      middleware('action, 'state),
      middleware('action, 'state)
    ) =>
    storeEnhancer('action, 'state) =
    "applyMiddleware";
  external applyMiddleware6 :
    (
      middleware('action, 'state),
      middleware('action, 'state),
      middleware('action, 'state),
      middleware('action, 'state),
      middleware('action, 'state),
      middleware('action, 'state)
    ) =>
    storeEnhancer('action, 'state) =
    "applyMiddleware";
  [@bs.module "redux"] external compose : ('a => 'b, 'c => 'a, 'c) => 'b = "";
};
