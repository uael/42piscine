let () =
  let d = Deck.newDeck in begin
    List.iter (fun c -> print_endline (Deck.Card.toStringVerbose c)) d;
    print_endline ("cards in deck: " ^ string_of_int (List.length d));
    List.iter print_endline (Deck.toStringList d);
    List.iter print_endline (Deck.toStringListVerbose d);
    let rec draw_all = function
    | (c, d) -> begin
      print_endline (Deck.Card.toStringVerbose c);
      draw_all (Deck.drawCard d)
    end
    | _ -> ()
    in draw_all (Deck.drawCard d)
  end
