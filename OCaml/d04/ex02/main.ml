let () =
  print_endline "clubs:";
  List.iter (fun c -> print_endline (Card.toString c)) Card.allClubs;
  List.iter (fun c -> print_endline (Card.toStringVerbose c)) Card.allClubs;
  print_endline "diamonds:";
  List.iter (fun c -> print_endline (Card.toString c)) Card.allDiamonds;
  List.iter (fun c -> print_endline (Card.toStringVerbose c)) Card.allDiamonds;
  print_endline "hearths:";
  List.iter (fun c -> print_endline (Card.toString c)) Card.allHearts;
  List.iter (fun c -> print_endline (Card.toStringVerbose c)) Card.allHearts;
  print_endline "spades:";
  List.iter (fun c -> print_endline (Card.toString c)) Card.allSpades;
  List.iter (fun c -> print_endline (Card.toStringVerbose c)) Card.allSpades;
  print_endline "all:";
  List.iter (fun c -> print_endline (Card.toString c)) Card.all;
  List.iter (fun c -> print_endline (Card.toStringVerbose c)) Card.all;
  let c = Card.newCard Card.Value.Jack Card.Color.Spade in begin
    print_endline ("with card: " ^ Card.toStringVerbose c);
    print_endline ("value: " ^ Card.Value.toStringVerbose (Card.getValue c));
    print_endline ("color: " ^ Card.Color.toStringVerbose (Card.getColor c));
    print_endline ("is of Spade: " ^ string_of_bool (Card.isOf c Card.Color.Spade));
    print_endline ("is of Diamond: " ^ string_of_bool (Card.isOf c Card.Color.Diamond));
    print_endline ("is Spade: " ^ string_of_bool (Card.isSpade c));
    print_endline ("is Diamond: " ^ string_of_bool (Card.isDiamond c));
    let c2 = Card.newCard Card.Value.As Card.Color.Club in begin
      print_endline ("max: " ^ Card.toStringVerbose (Card.max c c2));
      print_endline ("min: " ^ Card.toStringVerbose (Card.min c c2))
    end
  end;
  let c = Card.best Card.allHearts in
    print_endline ("best in allHearts: " ^ Card.toStringVerbose c)
