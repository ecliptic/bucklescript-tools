# bs-promise-router

A BuckleScript interface to [express-promise-router](https://www.npmjs.com/package/express-promise-router).

## Example

```reason
let router = PromiseRouter.make();
PromiseRouter.get(router, ~path="/", HttpUtils.heartbeat);
Express.App.use(app, asMiddleware(router));
```
