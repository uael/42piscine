let () =
  print_endline (string_of_bool ((new Atom.helium)#equals (new Atom.helium))) ;
  print_endline
    (string_of_bool ((new Atom.lithium)#equals (new Atom.beryllium))) ;
  let atoms =
    [ new Atom.hydrogen
    ; new Atom.helium
    ; new Atom.lithium
    ; new Atom.beryllium
    ; new Atom.boror
    ; new Atom.carbon
    ; new Atom.nitrogen
    ; new Atom.oxygen
    ; new Atom.fluorine ]
  in
  List.iter (fun a -> print_endline a#to_string) atoms
