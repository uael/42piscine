let rec converges f x n =
  if (n < 0) then false 
  else if (x = f x) then true 
  else converges f (f x) (n - 1)

let () =
  print_endline(if converges (( * ) 2) 2 5 then "nok" else "ok");
  print_endline(if converges (fun x -> x / 2) 2 3 then "ok" else "nok");
  print_endline(if converges (fun x -> x / 2) 2 2 then "ok" else "nok")
