# bs-node-debug

A temporary interface to `debug`, to be used until the `rebug` Node backend is ready.

## Example

```reason
let debug = Debug.make("my-app", "MyModule");

let debugExn = Debug.make("my-app", "MyModule:exn");

Js.Promise.catch((exn) => {
  debug("Unhandled error:");
  debugExn(exn);
  resolve(None)
})
```
