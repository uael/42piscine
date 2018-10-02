let ft_print_comb2 () =
  let p i             = if i < 10 then print_char '0'; print_int i
  in let rec c (a, b) =
    p a; print_char ' '; p b;
    match (a, b) with
      (98, 99) -> print_char '\n'
    | ( _, 99) -> print_char ','; print_char ' '; c(a + 1, a + 2)
    | ( _,  _) -> print_char ','; print_char ' '; c(    a, b + 1)
  in c(0, 1)

let () =
  ft_print_comb2()
