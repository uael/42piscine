let () =
  let molecules =
    [ new Molecule.trinitrotoluene
    ; new Molecule.water
    ; new Molecule.carbon_dioxyde
    ; new Molecule.carbon_monoxyde
    ; new Molecule.soot
    ; new Molecule.dioxygen ]
  in List.iter (fun x -> print_endline x#to_string) molecules ;
  print_endline
    (string_of_bool
       ((new Molecule.trinitrotoluene)#equals (new Molecule.trinitrotoluene))) ;
  print_endline
    (string_of_bool
       ((new Molecule.trinitrotoluene)#equals (new Molecule.water)))
