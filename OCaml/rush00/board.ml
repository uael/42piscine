type t = Player.m list

let toggle r c m  = function
  | [] -> failwith "error"
  | b ->
    if ((r > 2) || (r < 0)) || ((c > 2) && (c < 0))
    then failwith "Error value"
    else
      let i = c + (r * 3) in
      let f index e = if index = i then e
        else
          match e with
          | (X : Player.m) | O -> failwith "already in use"
          | _ -> m in
      List.mapi f b

let rec dump b =
  let f i a =
    print_string (Printf.sprintf " %s " (Player.string_of_mark a)) ;
    if (i mod 2) = 0 then print_char '\n'
  in List.iteri f b

let make n : t =
  let f i =
    if i < 0 then failwith "negatif value"
    else Player.N
  in List.init n f
