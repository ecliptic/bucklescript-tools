# bs-knex

BuckleScript utilities for working with the Node [knex](http://knexjs.org/) library.

## Example

```reason
let knex = Knex.make({
  "client": "pg",
  "connection": {
    "user": Config.Database.username,
    "password": Config.Database.password,
    "host": Config.Database.hostname,
    "port": Config.Database.port,
    "database": Config.Database.name
  },
  "pool": {
    "min": Config.Database.poolMin,
    "max": Config.Database.poolMax,
    "idleTimeoutMillis": Config.Database.poolIdle
  },
  "acquireConnectionTimeout": 2000
});

let users = [@bs] knex("users", Js.Nullable.null);

let promise = (user: Js.t('a)) =>
  users
  |> insert({
        "user_name": user##userName,
        "display_name": user##displayName,
        "email": user##email
      })
  |> returning("*")
  |> toPromise
  |> then_(handleResponse(~error="Unable to add User."))
  |> then_(pickFirst)
  |> handleUniqueError(
        ~name="users_email_unique",
        ~message="That email address is already in use."
      )
  |> handleUniqueError(
        ~name="users_user_name_unique",
        ~message="That user name is already in use."
      )
  |> handleDbErrors;
```
