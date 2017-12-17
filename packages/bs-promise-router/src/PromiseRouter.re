type t;

type promiseMiddleware =
  (Express.Request.t, Express.Response.t) => Js.Promise.t(Js.undefined(string));

[@bs.module] external make : 'a => t = "express-promise-router";

[@bs.send] external use : (t, promiseMiddleware) => unit = "";

[@bs.send] external useWithMany : (t, array(promiseMiddleware)) => unit = "use";

[@bs.send] external useOnPath : (t, ~path: string, promiseMiddleware) => unit = "use";

[@bs.send] external useOnPathWithMany : (t, ~path: string, array(promiseMiddleware)) => unit =
  "use";

[@bs.send] external get : (t, ~path: string, promiseMiddleware) => unit = "";

[@bs.send] external getWithMany : (t, ~path: string, array(promiseMiddleware)) => unit = "get";

[@bs.send] external post : (t, ~path: string, promiseMiddleware) => unit = "";

[@bs.send] external postWithMany : (t, ~path: string, array(promiseMiddleware)) => unit = "post";

external asMiddleware : t => Express.Middleware.t = "%identity";
