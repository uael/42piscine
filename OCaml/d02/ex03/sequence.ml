let sequence n =
  if n < 0 then ""
  else let rec cat r = function
    | [] -> r
    | e::l -> r ^ (string_of_int e) ^ cat r l
  in let rec next c e = function
    | [] -> [c; e]
    | t::q when t = e -> next (c + 1) t q
    | t::q -> c::e::(next 1 t q)
  in let rec loop n l =
    if n == 0 then cat "" l
    else match l with
      | [] -> ""
      | hd::tl -> loop (n - 1) (next 1 hd tl)
  in loop n [1]

let () =
  print_endline (sequence 0);
  print_endline (sequence 1);
  print_endline (sequence 2);
  print_endline (sequence 3);
  print_endline (sequence 4);
  print_endline (sequence 5);
  print_endline (sequence 6);
  print_endline (sequence 7);
  print_endline (sequence 8)
