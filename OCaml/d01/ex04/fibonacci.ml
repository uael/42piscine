let rec fibonacci = function
    n when n < 0 -> -1
  | n when n < 2 -> n
  | n -> fibonacci (n - 2) + fibonacci (n - 1)

let () =
  print_int(fibonacci(-42)); print_char '\n';
  print_int(fibonacci(1)); print_char '\n';
  print_int(fibonacci(3)); print_char '\n';
  print_int(fibonacci(6)); print_char '\n'
