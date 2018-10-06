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
    | (X : Player.m) | O -> true
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
  let f i =
    if i < 0 then failwith "negatif value"
    else Player.N
  in List.init (n * n) f

let draw dx dy b =
  let f i m = 
