# bs-chalk

[![version](https://img.shields.io/npm/v/bs-chalk.svg)](http://npm.im/bs-chalk)
[![downloads](https://img.shields.io/npm/dt/bs-chalk.svg)](http://npm.im/bs-chalk)
[![license](https://img.shields.io/npm/l/express.svg)](LICENSE)

BuckleScript tools for working with the Node [chalk](https://www.npmjs.com/package/chalk) library.

## Example

```reason
Js.log(
  Chalk.red("Express listen error: ")
  ++ Js.Option.getWithDefault("(no message)", Js.Exn.message(err))
)
```

## License

[BSD 2-Clause](LICENSE)
