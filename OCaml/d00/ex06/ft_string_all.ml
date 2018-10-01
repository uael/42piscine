let ft_string_all fn s =
  let rec loop i =
    if i < 0 then true else fn(s.[i]) && loop(i - 1)
  in loop(String.length s - 1)

let is_digit c = c >= '0' && c <= '9'

let () =
  print_endline (if ft_string_all is_digit "123" then "ok"  else "nok");
  print_endline (if ft_string_all is_digit "a12" then "nok" else "ok" );
  print_endline (if ft_string_all is_digit ""    then "ok"  else "nok")
