let player_test () =
  print_endline "** test Player module **\n";
  let p = Player.makeIA Player.X in Player.dump p;
  let p = Player.makeHuman Player.X "Bob" in Player.dump p;
  let p = Player.makeIA Player.O in Player.dump p;
  let p = Player.makeHuman Player.O "Bob" in Player.dump p
  (*let p = Player.makeHuman Player.O "Bob" in begin*)
    (*match Player.ask p with*)
    (*| (r, c) -> print_endline ((string_of_int r) ^ ", " ^ (string_of_int c))*)
  (*end;*)
  (*let p = Player.makeIA Player.X in begin*)
    (*match Player.ask p with*)
    (*| (r, c) -> print_endline ((string_of_int r) ^ ", " ^ (string_of_int c))*)
  (*end*)


let board_test () =
  print_endline "** test Board module **";
  let b = Board.make 3 in
  let b = Board.toggle (0, 2) Player.X b in 
  let b = Board.toggle (2, 2) Player.O b in 
  let b = Board.toggle (2, 0) Player.X b in 
  Board.dump b ; print_endline "\n\n" ;
  let l = Board.string_of b in
  let rec loop l i =
    match l with
    | [] -> ()
    | hd :: tl -> Printf.printf "Line %d\n%s\n\n" i hd ; loop tl (i + 1)
  in loop l 0
  (*mlet status = Board.winner_of b in
  match status with
  | Player.N -> print_endline "game in progresse"
  | Player.O -> print_endline "O win the game"
  | Player.X -> print_endline "X win the game" *)

let game_test () =
  print_endline "** test Game module **\n";
  (* Graphics.open_graph (""); *)
  let po = Player.makeHuman Player.O "Bob" in
  let px = Player.makeHuman Player.X "Jil" in
  let game = Game.make 3 po px in
  Game.run game 0

let () =
  game_test ()
