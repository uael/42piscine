let encode l =
  let rec lul ll i r =
    match ll with
    | [] -> r
    | a :: b :: c when a = b -> lul (b :: c) (i + 1) (           r)
    | a :: b :: c            -> lul (b :: c) (    1) (r @ [(i, a)])
    | a :: b                 -> r @ [(i, a)]
  in lul l 1 []

let rec print_list_tuple = function
| [] -> print_endline ""
| (i, j) :: tl  -> print_int i; print_string ","; print_int j; print_string "; "; print_list_tuple tl

let () =
  print_list_tuple (encode [ 0 ]);
  print_list_tuple (encode []);
  print_list_tuple (encode [ 0; 0; 0; 1; 1; 2; 2; 2; 2; 2 ])

