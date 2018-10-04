let gray n =
  let mv i =
    i lxor (i lsr 1)
  in let rec toa a i j =
    if j = n then a else
    if i land (1 lsl j) then a ^ "1" ^ toa a i (j + 1)
    else                     a ^ "0" ^ toa a i (j + 1)
  in 
      
