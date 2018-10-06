let player_test () =
  let p = Player.makeIA Player.X in Player.dump p;
  let p = Player.makeHuman Player.X "Bob" in Player.dump p;
  let p = Player.makeIA Player.O in Player.dump p;
  let p = Player.makeHuman Player.O "Bob" in Player.dump p;
  let p = Player.makeHuman Player.O "Bob" in begin
    match Player.ask p with
    | (r, c) -> print_endline ((string_of_int r) ^ ", " ^ (string_of_int c))
  end;
  let p = Player.makeIA Player.X in begin
    match Player.ask p with
    | (r, c) -> print_endline ((string_of_int r) ^ ", " ^ (string_of_int c))
  end


let () =
  player_test ()
