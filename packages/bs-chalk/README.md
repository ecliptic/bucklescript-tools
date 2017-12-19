# bs-chalk

BuckleScript tools for working with the Node [chalk](https://www.npmjs.com/package/chalk) library.

## Example

```re
Js.log(
  Chalk.red("Express listen error: ")
  ++ Js.Option.getWithDefault("(no message)", Js.Exn.message(err))
)
```
