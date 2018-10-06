type t = Player.m list

let toggle (r, c) m b =
  let i = c + (r * 3) in
  let f index e =
    if index <> i then e
    else m
  in
  List.mapi f b

let isTaken (r, c) b =
  let i = c + (r * 3) in
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
  loop b 0

let rec dump b =
  let f i a =
    print_string (Player.string_of_mark a) ;
    print_char (if (((i+ 1) mod 3) = 0) && i <> 0 then '\n' else ' ')
  in List.iteri f b

let make n : t =
  let rec m = function
  | 0 -> []
  | i -> Player.N::(m (i - 1))
  in m (n * n)

(* let draw dx dy b : *)
