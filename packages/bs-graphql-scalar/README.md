# bs-graphql-scalar

BuckleScript utilities for creating new GraphQL scalar types.

## Example

```reason
let resolvers = {
  "DateTime":
    makeScalar({
      "name": "DateTime",
      "description": "DateTime custom scalar Type",
      "serialize": (value) => value |> Js.Date.getTime |> Js.Float.toString |> Js.Nullable.return,
      "parseValue": (str) => str |> Js.Date.fromString |> Js.Nullable.return,
      "parseLiteral": (ast) => {
        open Language;
        let kind = getAstKind(ast);
        if (kind === intKind) {
          ast |> getAstValue |> TextUtils.parseInt_(10) |> Js.Nullable.return
        } else {
          Js.Nullable.null
        }
      }
    }),
};
```
