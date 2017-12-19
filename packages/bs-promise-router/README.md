# bs-promise-router

A BuckleScript interface to [express-promise-router](https://www.npmjs.com/package/express-promise-router).

## Example

```reason
let heartbeat = (_, res: Express.Response.t) => {
  Express.Response.sendString(res, "ok") |> ignore;
  Js.Promise.resolve(Js.undefined)
};

let router = PromiseRouter.make();

PromiseRouter.get(router, ~path="/", heartbeat);

Express.App.use(app, asMiddleware(router));
```
