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

let () =
  print_endline "** test Board module **\n";
  let b = make 3 in print_endline (Printf.sprintf "make %d" 3) ;
  dump b ; print_char '\n' ; print_endline "toggle (1, 2)" ;
  let bplus = toggle (1, 2) Player.X b in 
  dump bplus ;
  print_endline ("istaken (1, 2) -> " ^ (string_of_bool (isTaken (1, 2) bplus))) ;
  print_endline ("istaken (2, 3) -> " ^ (string_of_bool (isTaken (2, 3) bplus))) ;
