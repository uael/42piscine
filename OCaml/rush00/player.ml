type m = X | O | N
type k = AI | Human
type t = { m:m; k:k; n:string }
type a = Move of (int * int) | New | Exit
let make m k n    = { m=m; k=k; n=n }

let makeHuman m n = make m Human n
let makeAI m      = make m AI ""

let string_of_mark = function
| X -> "X"
| O -> "O"
| _ -> "_"

let string_of_kind = function
| AI -> "AI"
| Human -> "Human"

let mark_of p =
  p.m

let string_of p =
  (string_of_mark p.m) ^ ": " ^ if p.k = AI then string_of_kind AI
  else (p.n ^ " (" ^ (string_of_kind p.k) ^ ")")

let dump p = print_endline (string_of p)

let ask_trm p n =
  if p.k = AI then
    (Random.self_init (); Move(Random.int n, Random.int (n * n)))
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

let ask_gfx p =
  if p.k = AI then
    (Random.self_init (); Move(Random.int 8, Random.int 8))
  else let rec rd () =
    let (r, c) = (Graphics.read_key (), Graphics.read_key ()) in
    let uno = (int_of_char '1') in
    match (r, c) with
    | ('n', 'n') -> New
    | ('e', 'e') -> Exit
    | ('1'..'9', '1'..'9') ->
      Move(((int_of_char c) - uno), ((int_of_char r) - uno))
    | (_, _) -> print_endline "Incorrect format."; rd ()
  in rd ()
