type m = X | O | N
type k = IA | Human
type t = (m * k * string)

let string_of_mark = function
| X -> "X"
| O -> "O"
| _ -> "_"

let string_of_kind = function
| IA -> "IA"
| Human -> "Human"

let name_of = function
| (_, _, n) -> n

let string_of = function
| (m, IA, n) -> (string_of_mark m) ^ ": " ^ (string_of_kind IA)
| (m,  k, n) -> (string_of_mark m) ^ ": " ^ n ^ " (" ^ (string_of_kind k) ^ ")"

let dump p = print_endline (string_of p)

let ask = function
| (m, IA, n) -> (0 ,0)
| (m, Human, n) -> (0 ,0)

let make m k n    = (m, k, n)
let makeHuman m n = make m Human n
let makeIA m      = make m IA ""