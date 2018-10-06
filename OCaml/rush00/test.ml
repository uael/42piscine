let player_test () =
  let p = Player.makeIA Player.X in Player.dump p;
  let p = Player.makeHuman Player.X "Bob" in Player.dump p;
  let p = Player.makeIA Player.O in Player.dump p;
  let p = Player.makeHuman Player.O "Bob" in Player.dump p


let () =
  player_test ()
