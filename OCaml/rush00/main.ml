let usage filename =
  print_string filename ; print_string ": ";
  print_string "size 3 .. 6 Player1 [Player2]"

let () =
  let argv = Array.to_list Sys.argv in
  let filename = (List.hd argv) in
  let len = List.length argv in
  if len < 3 || len > 4 then usage filename
  else if (String.length (List.nth argv 1)) != 1 then usage filename
  else
    let c = (List.nth argv 1).[0] in let n = ((int_of_char c) - (int_of_char '1') + 1) in
    if n < 3 || n > 6 then usage filename
    else
      let po = Player.makeHuman Player.O (List.nth argv 2) in
      let px = if len < 4 then Player.makeIA Player.X else Player.makeHuman Player.X (List.nth argv 3)
      in let game = Game.make n po px in Game.run game 0
