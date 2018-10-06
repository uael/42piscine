type t = {
  p : Player.m list ; 
  n : int
}

let make n : t =
  let rec loop = function
  | 0 -> []
  | i -> Player.N::(loop (i - 1))
  in 
  let list_player = loop (n * n) in
  { p = list_player; n = n }


let toggle (r, c) m b =
  let i = c + (r * b.n) in
  let f index e =
    if index <> i then e
    else m
  in
  let newl = List.mapi f b.p in
  {p = newl; n = b.n}

let mark_of (r, c) b =
  let i = c + (r * b.n) in
  let f = function 
    | (Player.X : Player.m) -> Player.X
    | Player.O -> Player.O
    | _ -> Player.N
  in
  let rec loop l acc = match l with
    | [] -> Player.N (* no possible because r c must be valid *)
    | hd :: tl ->
      if acc = i then f hd
      else loop tl (acc + 1)
  in
  loop b.p 0

let isTaken (r, c) b =
  let i = c + (r * b.n) in
  let f = function 
    | (Player.X : Player.m) | Player.O -> true
    | _ -> false
  in
  let rec loop l acc = match l with
    | [] -> false
    | hd :: tl ->
      if acc = i then f hd
      else loop tl (acc + 1)
  in
  loop b.p 0

(*
let winner_of b =
  let rec loop l i =
    match l with
    | [] -> Player.N
    | hd :: tl ->
      ;
*)
let rec dump b =
  let f i a =
    print_string (Player.string_of_mark a) ;
    print_char (if (((i + 1) mod b.n) = 0) && i <> 0 then '\n' else ' ')
  in List.iteri f b.p

let draw dx dy b =
  let f i m =
    let x = (i mod b.n) in let y = (i / b.n) in
    print_int i ; print_string ": x -> "; print_int x ; print_string " y ->" ; print_int y ; print_char '\n' ;
    Graphics.moveto (dx + (x * 20)) (dy - (y * 20));
    Graphics.draw_string (Player.string_of_mark m)
  in List.iteri f b.p

let string_of b : string list = 
  let rec loop l acc line = match l with
    | [] -> line :: []
    | hd :: tl when (((acc + 1) mod b.n) = 0 && acc <> 0) ->
      (line ^ " " ^ Player.string_of_mark hd) :: (loop tl (acc + 1) "")
    | hd :: tl -> let sepa = if ((acc mod b.n) = 0) then "" else " "  in
      loop tl (acc + 1) (line ^ sepa ^ (Player.string_of_mark hd))
  in loop b.p 0 ""

let  () =
  print_endline "** test module **\n";
  let b = make 5 in print_endline (Printf.sprintf "make %d" 5) ;
  let b = toggle (1, 2) Player.X b in 
  let b = toggle (2, 0) Player.X b in 
  let b = toggle (1, 1) Player.X b in 
  dump b ;
  print_endline ("istaken (1, 2) -> " ^ (string_of_bool (isTaken (1, 2) b))) ;
  print_endline ("istaken (2, 3) -> " ^ (string_of_bool (isTaken (2, 3) b))) ;
  List.iteri (fun i str -> print_int i ; print_char '\n' ; print_endline str) (string_of b)
