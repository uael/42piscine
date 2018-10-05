let uncaesar n s =
  Cipher.caesar (-n) s

let unrot42 s =
  Cipher.caesar (-42) s

let xor n s =
  Cipher.xor n s

let rec ft_uncrypt n s = function
|	[] -> s
| h::t -> ft_uncrypt n (h n s) t
