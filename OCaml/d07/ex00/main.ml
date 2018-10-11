let () =
  let a = new People.people "Malou" in begin
    print_endline (a#to_string);
    a#talk;
    a#die;
  end