module Header = {
  type Redux.reAction +=
    | ToggleMenu;
  type action = Redux.action({. "_type": string, "reType": Redux.reAction});
  type state = {. "isMenuOpen": bool};
  let reducer = (state, action) =>
    switch action##reType {
    | ToggleMenu =>
      {"isMenuOpen": ! state##isMenuOpen} |> Js.Obj.assign(state) |> Js.Obj.assign(Js.Obj.empty())
    | _ => state
    };
  let actors = [||];
};

type state = {. "header": Header.state};

let rootReducer: Redux.reducer(Redux.action('action), state) =
  Redux.ReduxJs.combineReducers(~reducers={"header": Header.reducer});

let actors = Header.actors;

let create = () =>
  Redux.ReduxJs.createStore(
    ~reducer=rootReducer,
    ~enhancer=Redux.ReduxJs.applyMiddleware(Middleware.handleActors(actors)),
    ()
  );
