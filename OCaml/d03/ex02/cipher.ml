let rec caesar n s =
  if n < 0 then caesar (n + 128) s
  else String.map (fun c -> char_of_int ((int_of_char c + n) mod 128)) s

let rot42 s =
  caesar 42 s

let xor n s =
  String.map (fun c -> char_of_int (n lxor (int_of_char c))) s

let rec ft_crypt s = function
|	[] -> s
| h::t -> ft_crypt (h s) t
