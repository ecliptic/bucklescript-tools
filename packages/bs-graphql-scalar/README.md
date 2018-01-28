# bs-graphql-scalar

[![version](https://img.shields.io/npm/v/bs-graphql-scalar.svg)](http://npm.im/bs-graphql-scalar)
[![downloads](https://img.shields.io/npm/dt/bs-graphql-scalar.svg)](http://npm.im/bs-graphql-scalar)
[![license](https://img.shields.io/npm/l/express.svg)](LICENSE)

BuckleScript utilities for creating new GraphQL scalar types.

## Getting Started

To create a new scalar using the `graphql` JavaScript libary, you need three functions:

* `serialize` - Used when serializing results to send back to the client.
* `parseValue` - Used to parse input that was provided as variables by the client.
* `parseLiteral` - Used to parse input that was provided inline in the query.

## Example

```reason

let serializeDateTime = (value) =>
  value |> Js.Date.getTime |> Js.Float.toString |> Js.Nullable.return;

let parseDateTimeValue = (str) =>
  str |> Js.Date.fromString |> Js.Nullable.return;

let parseDateTimeLiteral = (ast) => {
  open Language;
  let kind = getAstKind(ast);
  if (kind === intKind) {
    ast |> getAstValue |> TextUtils.parseInt_(10) |> Js.Nullable.return
  } else {
    Js.Nullable.null
  }
};

let resolvers = {
  "DateTime":
    makeScalar({
      "name": "DateTime",
      "description": "DateTime custom scalar Type",
      "serialize": serializeDateTime,
      "parseValue": parseDateTimeValue,
      "parseLiteral": parseDateTimeLiteral
    }),
};
```

## License

[BSD 2-Clause](LICENSE)
