open Cipher;;
open Uncipher;;

let s = "Pleeassee encrypt meee !! ohhh pleaseee master !!! XO XO"

let () =
  let e = xor 42 s in
  let d = xor 42 e in
  print_endline d;

  let e = ft_crypt   42 s [xor; xor;   caesar; xor;   caesar] in
  let d = ft_uncrypt 42 e [xor; xor; uncaesar; xor; uncaesar] in
  print_endline d
