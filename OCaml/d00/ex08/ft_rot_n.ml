let ft_rot_n n s =
  let a     = int_of_char 'a' in
  let ua    = int_of_char 'A' in
  let map c =
    match c with
      'a'..'z' -> char_of_int((int_of_char c + n -  a) mod 26 +  a)
    | 'A'..'Z' -> char_of_int((int_of_char c + n - ua) mod 26 + ua)
    | _        -> c
  in String.map map s

let() =
  print_endline(ft_rot_n 1 "abcdefghijklmnopqrstuvwxyz");
  print_endline(ft_rot_n 1 "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  print_endline(ft_rot_n 13 "abcdefghijklmnopqrstuvwxyz");
  print_endline(ft_rot_n 42 "0123456789");
  print_endline(ft_rot_n 2 "OI2EAS67B9");
  print_endline(ft_rot_n 0 "Damned !");
  print_endline(ft_rot_n 42 "");
  print_endline(ft_rot_n 1 "NBzlk qnbjr !")
