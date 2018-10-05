let () =
  let rec print = function
	| [] -> ()
	| h::t -> print_endline
	  ((Value.toString h) ^ ":" ^ (Value.toStringVerbose h)); print t
  in print Value.all;
  let rec next v =
    print_endline (Value.toString v);
    try next (Value.next v)
    with invalid_arg -> print_endline "invalid arg caught"
  in next Value.T2;
  let rec previous v =
    print_endline (Value.toString v);
    try previous (Value.previous v)
    with invalid_arg -> print_endline "invalid arg caught"
  in previous Value.As
