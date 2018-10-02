let iter f x n =
  if n < 0 then (-1) else
  let rec loop = function
      (y, 0) -> y
    | (y, m) -> loop((f y), (m - 1))
  in loop(x, n)

let () =
  print_int(iter (fun x -> x * x) 2 4); print_char '\n';
  print_int(iter (fun x -> x * 2) 2 4); print_char '\n'
  
