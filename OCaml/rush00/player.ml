type m = X | O | N
type k = IA | Human
type t = { m:m; k:k; n:string }

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
    (Random.self_init (); (Random.int 8, Random.int 8))
  else begin
    print_endline ((string_of p) ^ "'s turn to play.");
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
  end

let make m k n    = { m=m; k=k; n=n }
let makeHuman m n = make m Human n
let makeIA m      = make m IA ""
