let repeat_x n =
  if n < 0 then "Error"
  else let rec f i =
    if i >= n then "" else "x" ^ f(i + 1)
  in f(0)

let () =
  print_endline(repeat_x(-1));
  print_endline(repeat_x 0);
  print_endline(repeat_x 1);
  print_endline(repeat_x 5)
