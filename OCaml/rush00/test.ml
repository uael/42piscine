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
  print_endline "** test Board module **\n";
  let b = Board.make 3 in print_endline (Printf.sprintf "make %d" 3) ;
  Board.dump b ; print_char '\n' ; print_endline "toggle (1, 2)" ;
  let bplus = Board.toggle (1, 2) Player.X b in 
  Board.dump bplus ;
  print_endline ("istaken (1, 2) -> " ^ (string_of_bool (Board.isTaken (1, 2) bplus))) ;
  print_endline ("istaken (2, 3) -> " ^ (string_of_bool (Board.isTaken (2, 3) bplus)))

(*let game_test () =*)
  (*print_endline "** test Game module **\n";*)
  (*Graphics.open_graph ("");*)
  (*let po = Player.makeHuman Player.O "Bob" in*)
  (*let px = Player.makeHuman Player.X "Jil" in*)
  (*let game = Game.make 3 po px in*)
  (*game.draw game*)

let () =
  player_test ();
  board_test ();
  (*game_test ()*)

