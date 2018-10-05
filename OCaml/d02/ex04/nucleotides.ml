type phosphate   = string
type deoxyribose = string
type nucleobase  = A | T | C | G | None
type nucleotide  = { p:phosphate; d:deoxyribose; n:nucleobase }

let generate_nucleotide c = {
  p = "phosphate";
  d = "deoxyribose";
  n = match c with
    | 'A' -> A
    | 'T' -> T
    | 'C' -> C
    | 'G' -> G
    | _ -> None
}

let () =
  let a = generate_nucleotide 'C'
  in begin 
    print_endline "{";
    print_endline ("  " ^ a.p);
    print_endline ("  " ^ a.d);
    print_endline ("  " ^ match a.n with
      | A -> "A"
      | T -> "T"
      | C -> "C"
      | G -> "G"
      | _ -> "?");
    print_endline "}"
  end
