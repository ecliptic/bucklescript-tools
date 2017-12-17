module Level = {
  type t =
    | None
    | Basic
    | Ansi256
    | TrueColor;
  let fromInt = (level) =>
    switch level {
    | 0 => None
    | 1 => Basic
    | 2 => Ansi256
    | 3 => TrueColor
    | _ => None
    };
  let toInt = (level) =>
    switch level {
    | None => 0
    | Basic => 1
    | Ansi256 => 2
    | TrueColor => 3
    };
};

type colorSupport = {. "level": int, "hasBasic": bool, "has256": bool, "has16m": bool};

[@bs.module "chalk"] external enabled : bool = "";

[@bs.module "chalk"] external level_ : int = "level";

[@bs.module "chalk"] external supportsColor : colorSupport = "";

[@bs.module "chalk"] external stripColor : string => string = "";

[@bs.module "chalk"] external hasColor : string => bool = "";

[@bs.module "chalk"] external visible : string => bool = "";

/* Styles */
[@bs.module "chalk"] external reset : string => string = "";

[@bs.module "chalk"] external bold : string => string = "";

[@bs.module "chalk"] external dim : string => string = "";

[@bs.module "chalk"] external italic : string => string = "";

[@bs.module "chalk"] external underline : string => string = "";

[@bs.module "chalk"] external inverse : string => string = "";

[@bs.module "chalk"] external hidden : string => string = "";

[@bs.module "chalk"] external strikethrough : string => string = "";

/* Colors */
[@bs.module "chalk"] external black : string => string = "";

[@bs.module "chalk"] external red : string => string = "";

[@bs.module "chalk"] external green : string => string = "";

[@bs.module "chalk"] external yellow : string => string = "";

[@bs.module "chalk"] external blue : string => string = "";

[@bs.module "chalk"] external magenta : string => string = "";

[@bs.module "chalk"] external cyan : string => string = "";

[@bs.module "chalk"] external white : string => string = "";

[@bs.module "chalk"] external gray : string => string = "";

[@bs.module "chalk"] external grey : string => string = "";

[@bs.module "chalk"] external blackBright : string => string = "";

[@bs.module "chalk"] external redBright : string => string = "";

[@bs.module "chalk"] external greenBright : string => string = "";

[@bs.module "chalk"] external yellowBright : string => string = "";

[@bs.module "chalk"] external blueBright : string => string = "";

[@bs.module "chalk"] external magentaBright : string => string = "";

[@bs.module "chalk"] external cyanBright : string => string = "";

[@bs.module "chalk"] external witeBright : string => string = "";

[@bs.module "chalk"] external bgBlack : string => string = "";

[@bs.module "chalk"] external bgRed : string => string = "";

[@bs.module "chalk"] external bgGreen : string => string = "";

[@bs.module "chalk"] external bgYellow : string => string = "";

[@bs.module "chalk"] external bgBlue : string => string = "";

[@bs.module "chalk"] external bgMagenta : string => string = "";

[@bs.module "chalk"] external bgCyan : string => string = "";

[@bs.module "chalk"] external bgWhite : string => string = "";

[@bs.module "chalk"] external bgBlackBright : string => string = "";

[@bs.module "chalk"] external bgRedBright : string => string = "";

[@bs.module "chalk"] external bgGreenBright : string => string = "";

[@bs.module "chalk"] external bgYellowBright : string => string = "";

[@bs.module "chalk"] external bgBlueBright : string => string = "";

[@bs.module "chalk"] external bgMagentaBright : string => string = "";

[@bs.module "chalk"] external bgCyanBright : string => string = "";

[@bs.module "chalk"] external bgWhiteBright : string => string = "";

/* Exact colors */
[@bs.module "chalk"] external hex : string => string = "";

[@bs.module "chalk"] external rgb_ : [@bs] ((int, int, int) => string) = "rgb";

[@bs.module "chalk"] external hsl_ : [@bs] ((int, int, int) => string) = "hsl";

[@bs.module "chalk"] external hsv_ : [@bs] ((int, int, int) => string) = "hsv";

[@bs.module "chalk"] external hwb_ : [@bs] ((int, int, int) => string) = "hwb";

[@bs.module "chalk"] external bgHex : string => string = "";

[@bs.module "chalk"] external bgRgb_ : [@bs] ((int, int, int) => string) = "bgRgb";

[@bs.module "chalk"] external bgHsl_ : [@bs] ((int, int, int) => string) = "bgHsl";

[@bs.module "chalk"] external bgHsv_ : [@bs] ((int, int, int) => string) = "bgHsv";

[@bs.module "chalk"] external bgHwb_ : [@bs] ((int, int, int) => string) = "bgHwb";

[@bs.module "chalk"] external keyword : string => string = "";

/* Convenience Methods */
let level: Level.t = level_ |> Level.fromInt;

let rgb = (~r: int, ~g: int, ~b: int) => [@bs] rgb_(r, g, b);

let hsl = (~h: int, ~s: int, ~l: int) => [@bs] hsl_(h, s, l);

let hsv = (~h: int, ~s: int, ~v: int) => [@bs] hsv_(h, s, v);

let hwb = (~h: int, ~w: int, ~b: int) => [@bs] hwb_(h, w, b);

let bgRgb = (~r: int, ~g: int, ~b: int) => [@bs] bgRgb_(r, g, b);

let bgHsl = (~h: int, ~s: int, ~l: int) => [@bs] bgHsl_(h, s, l);

let bgHsv = (~h: int, ~s: int, ~v: int) => [@bs] bgHsv_(h, s, v);

let bgHwb = (~h: int, ~w: int, ~b: int) => [@bs] bgHwb_(h, w, b);
