let repeat_string ?(str="x") n =
  if n < 0 then "Error"
  else let rec f i =
    if i >= n then "" else str ^ f(i + 1)
  in f(0)

let () =
  print_endline(repeat_string(-1));
  print_endline(repeat_string 0);
  print_endline(repeat_string ~str:"Toto" 1);
  print_endline(repeat_string 2);
  print_endline(repeat_string ~str:"a" 5);
  print_endline(repeat_string ~str:"what" 3)
