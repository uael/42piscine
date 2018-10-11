let () =
  let a = new People.people "Malou" in
  let b = new Doctor.doctor "Malou+" 999 (new People.people "Malou++") in
  let c = new Dalek.dalek in begin
    a#talk;
    b#talk;
    c#talk;
    b#travel_in_time 2018 2142;
    b#talk;
    a#talk;
    c#talk;
    b#use_sonic_screwdriver;
    c#talk;
    b#talk;
    a#talk;
    b#kick 50;
    b#kick 50;
    b#kick 50;
    b#kick 50;
    c#exterminate a
  end