type query;

type t('options) = [@bs] ((string, 'options) => query);

external toPromise : query => Js.Promise.t('a) = "%identity";

[@bs.module] external make : 'connectionOpts => t('options) = "knex";

[@bs.send] external raw : (t('options), string) => Js.Promise.t('b) = "";

/* Query Interface */
[@bs.send.pipe : query] external select : 'a => query = "";

[@bs.send.pipe : query] external as_ : 'a => query = "as";

[@bs.send.pipe : query] external columns : 'a => query = "";

[@bs.send.pipe : query] external column : 'a => query = "";

[@bs.send.pipe : query] external from : 'a => query = "";

[@bs.send.pipe : query] external into : 'a => query = "";

[@bs.send.pipe : query] external table : 'a => query = "";

[@bs.send.pipe : query] external distinct : 'a => query = "";

/* Joins */
[@bs.send.pipe : query] external join : 'a => query = "";

[@bs.send.pipe : query] external joinRaw : 'a => query = "";

[@bs.send.pipe : query] external innerJoin : 'a => query = "";

[@bs.send.pipe : query] external leftJoin : 'a => query = "";

[@bs.send.pipe : query] external leftOuterJoin : 'a => query = "";

[@bs.send.pipe : query] external rightJoin : 'a => query = "";

[@bs.send.pipe : query] external rightOuterJoin : 'a => query = "";

[@bs.send.pipe : query] external outerJoin : 'a => query = "";

[@bs.send.pipe : query] external fullOuterJoin : 'a => query = "";

[@bs.send.pipe : query] external crossJoin : 'a => query = "";

/* Withs */
[@bs.send.pipe : query] external with_ : 'a => query = "with";

[@bs.send.pipe : query] external withRaw : 'a => query = "";

[@bs.send.pipe : query] external withSchema : 'a => query = "";

[@bs.send.pipe : query] external withWrapped : 'a => query = "";

/* Wheres */
[@bs.send.pipe : query] external where : 'a => query = "";

[@bs.send.pipe : query] external andWhere : 'a => query = "";

[@bs.send.pipe : query] external orWhere : 'a => query = "";

[@bs.send.pipe : query] external whereNot : 'a => query = "";

[@bs.send.pipe : query] external andWhereNot : 'a => query = "";

[@bs.send.pipe : query] external orWhereNot : 'a => query = "";

[@bs.send.pipe : query] external whereRaw : 'a => query = "";

[@bs.send.pipe : query] external orWhereRaw : 'a => query = "";

[@bs.send.pipe : query] external andWhereRaw : 'a => query = "";

[@bs.send.pipe : query] external whereWrapped : 'a => query = "";

[@bs.send.pipe : query] external havingWrapped : 'a => query = "";

[@bs.send.pipe : query] external whereExists : 'a => query = "";

[@bs.send.pipe : query] external orWhereExists : 'a => query = "";

[@bs.send.pipe : query] external whereNotExists : 'a => query = "";

[@bs.send.pipe : query] external orWhereNotExists : 'a => query = "";

[@bs.send.pipe : query] external whereIn : 'a => query = "";

[@bs.send.pipe : query] external orWhereIn : 'a => query = "";

[@bs.send.pipe : query] external whereNotIn : 'a => query = "";

[@bs.send.pipe : query] external orWhereNotIn : 'a => query = "";

[@bs.send.pipe : query] external whereNull : 'a => query = "";

[@bs.send.pipe : query] external orWhereNull : 'a => query = "";

[@bs.send.pipe : query] external whereNotNull : 'a => query = "";

[@bs.send.pipe : query] external orWhereNotNull : 'a => query = "";

[@bs.send.pipe : query] external whereBetween : 'a => query = "";

[@bs.send.pipe : query] external orWhereBetween : 'a => query = "";

[@bs.send.pipe : query] external andWhereBetween : 'a => query = "";

[@bs.send.pipe : query] external whereNotBetween : 'a => query = "";

[@bs.send.pipe : query] external orWhereNotBetween : 'a => query = "";

[@bs.send.pipe : query] external andWhereNotBetween : 'a => query = "";

/* Group By */
[@bs.send.pipe : query] external groupBy : 'a => query = "";

[@bs.send.pipe : query] external groupByRaw : 'a => query = "";

/* Order By */
[@bs.send.pipe : query] external orderBy : 'a => query = "";

[@bs.send.pipe : query] external orderByRaw : 'a => query = "";

/* Union */

[@bs.send.pipe : query] external union : 'a => query = "";

[@bs.send.pipe : query] external unionAll : 'a => query = "";

/* Having */

[@bs.send.pipe : query] external having : 'a => query = "";
[@bs.send.pipe : query] external andHaving : 'a => query = "";
[@bs.send.pipe : query] external havingRaw : 'a => query = "";
[@bs.send.pipe : query] external orHaving : 'a => query = "";
[@bs.send.pipe : query] external orHavingRaw : 'a => query = "";

/* Clear */

[@bs.send.pipe : query] external clearSelect : 'a => query = "";
[@bs.send.pipe : query] external clearWhere : 'a => query = "";

/* Paging */

[@bs.send.pipe : query] external offset : int => query = "";
[@bs.send.pipe : query] external limit : int => query = "";

/* Aggregation */

[@bs.send.pipe : query] external count : (Js.Nullable.t(string)) => query = "";
[@bs.send.pipe : query] external countDistinct : (Js.Nullable.t(string)) => query = "";
[@bs.send.pipe : query] external min : (string) => query = "";
[@bs.send.pipe : query] external max : (string) => query = "";
[@bs.send.pipe : query] external sum : (string) => query = "";
[@bs.send.pipe : query] external sumDistinct : (string) => query = "";
[@bs.send.pipe : query] external avg : (string) => query = "";
[@bs.send.pipe : query] external avgDistinct : (string) => query = "";
[@bs.send.pipe : query] external increment : (string, Js.Nullable.t(int)) => query = "";
[@bs.send.pipe : query] external decrement : (string, Js.Nullable.t(int)) => query = "";

/* Others */

[@bs.send.pipe : query] external first : 'a => query = "";

[@bs.send.pipe : query] external debug : Js.boolean => query = "";

[@bs.send.pipe : query] external pluck : string => query = "";

[@bs.send.pipe : query] external insert_ : ('a, Js.Nullable.t(string)) => query = "insert";

[@bs.send.pipe : query] external update_ : ('a, Js.Nullable.t(string)) => query = "update";

[@bs.send.pipe : query] external updateSet : (string, 'a, Js.Nullable.t(string)) => query = "update";

[@bs.send.pipe : query] external returning : 'a => query = "";

[@bs.send.pipe : query] external del_ : ('a, Js.Nullable.t(string)) => query = "del";

[@bs.send.pipe : query] external truncate : unit => query = "";

[@bs.send.pipe : query] external transacting : 'a => query = "";

[@bs.send.pipe : query] external connection : 'a => query = "";

[@bs.send.pipe : query] external clone : unit => query = "";

/* Convenience Functions */

let insert = (~returning=Some("*"), data) => insert_(data, Js.Nullable.from_opt(returning));

let update = (~returning=Some("*"), data) => update_(data, Js.Nullable.from_opt(returning));

let del = (~returning=Some("*"), data) => del_(data, Js.Nullable.from_opt(returning));

let delete = del;
