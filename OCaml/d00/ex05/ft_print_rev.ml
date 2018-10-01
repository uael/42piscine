let ft_print_rev s =
  for i =  String.length s - 1 downto 0 do
    print_char s.[i]
  done;
  print_char '\n' 

let () =
  ft_print_rev "";
  ft_print_rev "Hello world !"
