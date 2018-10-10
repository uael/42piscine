module StringHash = struct
	type t = string
	let equal (a: t) (b: t) = a = b
	let hash (s: t) =
	  let rec lul h = function
	  | i when i = String.length s -> h
	  | i -> lul ((h lsl 5) - h + (int_of_char s.[i])) (i + 1)
	  in lul 0 0
end

module StringHashtbl = Hashtbl.Make(StringHash)

let () =
  let ht = StringHashtbl.create 5 in
  let values = [ "Hello"; "world"; "42"; "Ocaml"; "H" ] in
  let pairs = List.map (fun s -> (s, String.length s)) values in
  List.iter (fun (k,v) -> StringHashtbl.add ht k v) pairs;
  StringHashtbl.iter (fun k v -> Printf.printf "k = \"%s\", v = %d\n" k v) ht
