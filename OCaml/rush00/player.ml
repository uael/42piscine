type m = X | O | N
type k = IA | Human
type t = { m:m; k:k; n:string }
type a = | Move of (int * int) | New | Exit

let string_of_mark = function
| X -> "X"
| O -> "O"
| _ -> "_"

let string_of_kind = function
| IA -> "IA"
| Human -> "Human"

let mark_of p =
  p.m

let string_of p =
  (string_of_mark p.m) ^ ": " ^ if p.k = IA then string_of_kind IA
  else (p.n ^ " (" ^ (string_of_kind p.k) ^ ")")

let dump p = print_endline (string_of p)

let ask p =
  if p.k = IA then
    (Random.self_init (); Move(Random.int 8, Random.int 8))
  else let rec rd () =
    let ln = read_line () in
    if String.length ln != 3 then (print_endline "Incorrect format."; rd ())
    else if ln.[1] != ' '    then (print_endline "Incorrect format."; rd ())
    else let uno = (int_of_char '1') in
      let r = ln.[0] in let c = ln.[2] in
      match (r, c) with
      | ('n', 'n') -> New
      | ('e', 'e') -> Exit
      | ('1'..'9', '1'..'9') ->
        Move(((int_of_char r) - uno), ((int_of_char c) - uno))
      | (_, _) -> print_endline "Incorrect format."; rd ()
  in rd ()

let ask2 p =
  if p.k = IA then
    (Random.self_init (); Move(Random.int 8, Random.int 8))
  else let rec rd () =
    let (r, c) = (Graphics.read_key (), Graphics.read_key ()) in
    let uno = (int_of_char '1') in
    match (r, c) with
    | ('n', 'n') -> New
    | ('e', 'e') -> Exit
    | ('1'..'9', '1'..'9') ->
      Move(((int_of_char r) - uno), ((int_of_char c) - uno))
    | (_, _) -> print_endline "Incorrect format."; rd ()
  in rd ()

let make m k n    = { m=m; k=k; n=n }
let makeHuman m n = make m Human n
let makeIA m      = make m IA ""
