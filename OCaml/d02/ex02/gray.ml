let gray n =
  if n < 0 then () else
  let rec print i j =
    print_char (if i land (1 lsl j) != 0 then '1' else '0');
    if j > 0 then print i (j - 1)
  in let rec lul i =
    print (i lxor (i lsr 1)) (n - 1);
    if i < (1 lsl n) - 1 then begin
      print_char ' '; lul (i + 1)
    end
  in lul 0; print_char '\n'

let () =
  gray 0;
  gray 1;
  gray 2;
  gray 3
