open Cipher;;
open Uncipher;;

let s = "Pleeassee encrypt meee !! ohhh pleaseee master !!! XO XO"

let () =
  let e = xor 42 s in
  let d = xor 42 e in
  print_endline d;

  let e = ft_crypt   s [(xor 23);   (caesar 42); (xor 64);   (caesar 21)] in
  let d = ft_uncrypt e [(uncaesar 21); (xor 64); (uncaesar 42); (xor 23)] in
  print_endline d
