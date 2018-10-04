let crossover x y =
  let rec lul a b r =
    match (a, b) with
    | ([], _) -> r
    | (hx :: tx, []      )              -> lul tx y r
    | (hx :: tx, hy :: ty) when hx = hy -> lul tx y (r @ [hx])
    | (hx :: tx, hy :: ty)              -> lul (hx :: tx) ty r
  in lul x y []

let rec print_list = function 
| [] -> ()
| e::l -> print_int e ; print_string " " ; print_list l

let () =
  print_list (crossover [ 0; 5; 1; 4; 2 ] [ 5; 7; 2; 4; 9 ])
  
