let () =
  let atoms =
    [ new Alkane.methane
    ; new Alkane.ethane
    ; new Alkane.propane
    ; new Alkane.butane
    ; new Alkane.pentane
    ; new Alkane.hexane
    ; new Alkane.heptane
    ; new Alkane.octane
    ; new Alkane.nonane ]
  in
  List.iter (fun x -> print_endline x#to_string) atoms
