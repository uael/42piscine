let ackermann m n =
  if m < 0 || n < 0 then (-1)
  else let rec f = function
      (0, b) -> b + 1
    | (a, 0) -> f(a - 1, 1)
    | (a, b) -> f(a - 1, f(a, b - 1))
  in f(m, n)

let () =
  print_int(ackermann (-1) 7); print_char '\n';
  print_int(ackermann 0 0);    print_char '\n';
  print_int(ackermann 2 3);    print_char '\n'

