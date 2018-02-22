type actor('action, 'state) =
  (Redux.action('action), Redux.dispatch('action), unit => 'state) =>
  Js.Nullable.t(Redux.action('action));

type handleActors('action, 'state) =
  (
    array(actor('action, 'state)),
    Redux.store('action, 'state),
    Redux.dispatch('action),
    Redux.action('action)
  ) =>
  Redux.action('action);

let handleActors: handleActors('action, 'state) =
  (actors, store, next, action) => {
    let (dispatch, getState) = (store##dispatch, store##getState);
    let result = next(action);
    actors
    |> Js.Array.forEach(
         (actor) => {
           let response = actor(action, dispatch, getState);
           switch (response |> Js.Nullable.to_opt) {
           | Some(action) => dispatch(action) |> ignore
           | None => ()
           }
         }
       );
    result
  };
/* let handleActors = (actors: ?(Function[])) => (store: *) => (next: Function) => (
           action: *
         ) => {
           const result = next(action)

           if (actors) {
             actors.forEach((actor) => {
               const response = actor(action, store.dispatch, store.getState)
               if (response) store.dispatch(response)
             })
           }

           return result
         }

         export default {
           ha


   ndleAct   } */
