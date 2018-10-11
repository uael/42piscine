let () =
  let a = new People.people "Malou" in begin
    print_endline (a#to_string);
    a#talk;
    a#die
  end in
  let b = new Doctor.doctor "Malou+" 999 (new People.people "Malou") in begin
    print_endline (b#to_string);
    b#talk;
    b#travel_in_time 2018 2142;
    b#use_sonic_screwdriver;
    b#kick 50;
    b#kick 50;
    b#kick 50;
    b#kick 50;
    b#kick 50;
    b#kick 50;
  end