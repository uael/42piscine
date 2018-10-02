let ft_is_palindrome s =
  let len = String.length s
  in
    if len = 0 then true else 
    let rec loop i =
      if i < 0 then true
      else s.[i] = s.[len - 1 - i] && loop(i - 1)
    in loop(len / 2)

let () =
  print_endline(if ft_is_palindrome "radar" then "ok" else "nok");
  print_endline(if ft_is_palindrome "madam" then "ok" else "nok");
  print_endline(if ft_is_palindrome "raddar" then "ok" else "nok");
  print_endline(if ft_is_palindrome "car" then "nok" else "ok");
  print_endline(if ft_is_palindrome "" then "ok" else "nok")
