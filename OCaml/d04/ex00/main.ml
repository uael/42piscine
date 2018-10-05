let () =
  let rec print = function
  | [] -> ()
  | h::t -> print_endline
    ((Color.toString h) ^ ":" ^ (Color.toStringVerbose h)); print t
  in print Color.all
