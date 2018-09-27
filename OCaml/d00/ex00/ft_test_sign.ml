let ft_test_sign x =
  print_endline (if x < 0 then "negative" else "positive")

let() =
  ft_test_sign 42;;
  ft_test_sign 0;;
  ft_test_sign (-42);;
