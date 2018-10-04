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

let string_of_nucleotide n =
  "{" ^ "p='" ^ n.p ^ "', d='" ^ n.d ^ "', n=" ^
    begin match n.n with
      | A -> "A"
      | T -> "T"
      | C -> "C"
      | G -> "G"
      | _ -> "?"
    end ^ "}"

type helix = nucleotide list

let nucleo n =
  match n with
    | 0 -> 'A'
    | 1 -> 'T'
    | 2 -> 'C'
    | 3 -> 'G'
    | _ -> '?'

let generate_helix n =
  Random.self_init ();
  let rec gen h = function
    | 0 -> h
    | n -> gen (generate_nucleotide(nucleo (Random.int 4))::h) (n - 1)
  in gen [] n

let helix_to_string h =
  let rec loop s = function
    | [] -> s
    | n::o::t -> s ^ (string_of_nucleotide n) ^ "\n" ^ loop s (o::t)
    | n::t -> s ^ (string_of_nucleotide n) ^ loop s t
  in loop "" h

let rec complementary_helix = function
  | [] -> []
  | h::t -> (generate_nucleotide (match h.n with
     | A -> 'T'
     | T -> 'A'
     | C -> 'G'
     | G -> 'C'
     | _ -> '?'))::(complementary_helix t)

let () =
  print_endline ("empty:\n" ^ (helix_to_string (generate_helix 0)));
  print_endline ("helix 5:\n" ^ (helix_to_string (generate_helix 5)));
  let a = generate_helix 6
  in begin
    print_endline ("helix 6:\n" ^ (helix_to_string a));
    print_endline ("complementary:\n" ^ (helix_to_string (complementary_helix a)));
  end
