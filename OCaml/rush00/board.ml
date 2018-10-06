type t = Player.m list

let toggle (r, c) m  = function
  | [] -> failwith "error"
  | b ->
    if ((r > 2) || (r < 0)) || ((c > 2) && (c < 0))
    then failwith "Error value"
    else
      let i = c + (r * 3) in
      let f index e = if index <> i then e
        else
          match e with
          | (X : Player.m) | O -> failwith "already in use"
          | _ -> m in
      List.mapi f b

let rec dump b =
  let f i a =
    print_string (Printf.sprintf "%s%c" (Player.string_of_mark a) (
    if (((i+ 1) mod 3) = 0) && i <> 0 then '\n' else ' ' ))
  in List.iteri f b

let make n : t =
  let f i =
    if i < 0 then failwith "negatif value"
    else Player.N
  in List.init n f

let () =
  print_endline "** test Board module **\n";
  let b = make 9 in
  dump b ; print_char '\n' ;
  let bplus = toggle (1, 2) Player.X b in 
  dump bplus
