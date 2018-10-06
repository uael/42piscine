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
| (m, IA, n) -> Random.self_init (); (Random.int 8, Random.int 8)
| p ->
  print_endline ((string_of p) ^ "'s turn to play.");
  let buffer = Bytes.create 5 in
  let rec rd () =
    let ln = read_line () in
    if String.length ln != 3 then (print_endline "Incorrect format."; rd ())
    else if ln.[1] != ' '    then (print_endline "Incorrect format."; rd ())
    else let uno = (int_of_char '1') in
      let r = ln.[0] in let c = ln.[2] in
      match (r, c) with
      | ('1'..'9', '1'..'9') ->
        (((int_of_char r) - uno), ((int_of_char c) - uno))
      | (_, _) -> print_endline "Incorrect format."; rd ()
  in rd ()

let make m k n    = (m, k, n)
let makeHuman m n = make m Human n
let makeIA m      = make m IA ""
