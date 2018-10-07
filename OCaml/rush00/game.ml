type t = { b:Board.t list; o:Player.t; x:Player.t; n:int }

let makeGrid n =
  let rec m = function
    | 0 -> []
    | i -> (Board.make n)::m (i - 1)
  in m (n * n)

let make n po px = { b = makeGrid n; o = po; x = px; n = n }
let copy g b = { b = b; o = g.o; x = g.x; n = g.n }

let is_not_legal (r, c) g =
  let idx = (((r / g.n) * g.n) + (c / g.n)) in
  let b = List.nth g.b idx in
  Board.is_not_legal (r mod g.n, c mod g.n) b

let toggle (r, c) p g =
  let idx = (((r / g.n) * g.n) + (c / g.n)) in
  let b = List.mapi
      (fun i e ->
         if i = idx then Board.toggle (r mod g.n, c mod g.n) (Player.mark_of p) e
         else e)
      g.b
  in copy g b

let winner_of g =
  let b = List.map Board.winner_of g.b in
  let same value value1 = value in
  let win m i =
    let rec check (y, x) opey opex =
      if ((y < 0) || (y >= g.n)) || ((x < 0) || (x >= g.n)) then true
      else
        let newi = x + (y * g.n) in
        if ((newi < 0) || (newi >= (List.length b))) then false else
          let newp = List.nth b newi in match (m, newp) with
          | (Board.Mark(a), Board.Mark(b)) when a <> b -> false
          | (_, Board.None) | (Board.None, _) -> false
          | (_, _) -> check ((opey y 1), (opex x 1)) opey opex
    in
    let y = i / g.n in let x = i mod g.n in
    let top = check ((y - 1), x) (-) same in let bottom = check ((y + 1), x) (+) same in
    let left = check (y, (x - 1)) same (-) in let rigth = check (y, (x + 1)) same (+) in
    let bottomRigth = check ((y + 1), (x + 1)) (+) (+) in let topLeft = check ((y - 1), (x - 1)) (-) (-) in
    let bottomLeft = check ((y + 1), (x - 1)) (+) (-) in let topRigth = check ((y - 1), (x + 1)) (-) (+) in
    ((top && (y > 0)) && (bottom && (y < (g.n - 1)))) ||
    ((left && (x > 0)) && (rigth && (x < (g.n - 1)))) ||
    ((bottomRigth && (y > 0) && (x < (g.n - 1))) && (topLeft && (y < (g.n - 1)) && (x > 0))) ||
    ((bottomLeft && (y > 0) && (x > 0)) && (topRigth && (y < (g.n - 1)) && (x < (g.n -1))))
  in
  let rec loop l i =
    match l with
    | [] ->
      if (List.for_all (fun p -> p = Board.Mark(Player.N)) b) then Board.Mark(Player.N) else Board.None
    | hd :: tl when hd = Board.Mark(Player.N) -> loop tl (i + 1)
    | hd :: tl -> if win hd i then hd else loop tl (i + 1)
  in loop b 0

let draw_trm g =
  let b = List.map (fun b -> Board.string_of b) g.b in
  let rec loop_game_line = function
    | r when r = g.n -> ()
    | r ->
      begin
        let rec loop_game_col = function
          | c when c = g.n -> ()
          | c ->
            begin
              let rec loop_board_line = function
                | bline when bline = g.n -> ()
                | bline ->
                  begin
                    let idx = ((r * g.n) + bline) in
                    let bs = List.nth b idx in
                    let s = List.nth bs c in print_string s ;
                    print_char (if ((idx + 1) mod g.n) <> 0 then '|' else '\n') ;
                    loop_board_line (bline + 1)
                  end
              in loop_board_line 0 ;
              loop_game_col (c + 1)
            end
        in loop_game_col 0 ;
        List.iter (fun x -> print_string "--") b ; print_char '\n';
        loop_game_line (r + 1)
      end
  in loop_game_line 0

let draw_gfx g =
  Graphics.clear_graph ();
  let rec draw_b i = function
  | [] -> ()
  | b::t -> begin
    let x = i mod g.n in let y = g.n - (i / g.n) in
    Board.draw (x * (g.n * 20)) (y * (g.n * 20)) b;
    draw_b (i + 1) t
  end in draw_b 0 g.b

let ai_ask g =
  let rec ver = function
    | r when r = g.n -> Player.NoMove
    | r ->
      begin
        let rec line = function
        | c when c = g.n -> []
        | c ->
          let idx = ((r * g.n) + c)
          in (c, (List.nth g.b idx)) :: line (c + 1)
        in let l = line 0
        in let ll = List.map (fun (c, b) -> Board.winner_of b) l
        in if (List.for_all
          (fun m -> m = Board.None || m = Board.Mark(Player.X))
            ll) then
          let rec f = function
          | [] -> ver (r + 1)
          | (c, b)::t when (Board.winner_of b) = Board.None -> begin
            match Board.find_mv b with
            | Player.NoMove -> f t
            | Player.Move(br, bc) -> Player.Move((r * g.n) + br, (c * g.n) + bc)
          end
          | h::t -> f t
          in f l
        else ver (r + 1)
      end
  in let rec hor = function
    | c when c = g.n -> Player.NoMove
    | c ->
      begin
        let rec line = function
        | r when r = g.n -> []
        | r ->
          let idx = ((r * g.n) + c)
          in (r, (List.nth g.b idx)) :: line (r + 1)
        in let l = line 0
        in let ll = List.map (fun (r, b) -> Board.winner_of b) l
        in if (List.for_all
          (fun m -> m = Board.None || m = Board.Mark(Player.X))
            ll) then
          let rec f = function
          | [] -> hor (c + 1)
          | (r, b)::t when (Board.winner_of b) = Board.None -> begin
            match Board.find_mv b with
            | Player.NoMove -> f t
            | Player.Move(br, bc) -> Player.Move((r * g.n) + br, (c * g.n) + bc)
          end
          | h::t -> f t
          in f l
        else hor (c + 1)
      end
  in match ver 0 with
  | Player.NoMove -> begin
    match hor 0 with
    | Player.NoMove -> let rec lol () =
      let mv = (Random.self_init (); Move(Random.int (n * n), Random.int (n * n)))
      in if is_not_legal mv g then lol () else mv
      in lol ()
    | m -> m
  end
  | m -> m

let rec run g i =
  let rec retry () =
    print_string "retry ? (yes no): ";
    let rep = read_line () in
    if rep = "yes" then true
    else if rep = "no" then false
    else retry ()
  in
  let p = match i with
    | i when (i mod 2) = 0 -> g.o
    | i -> g.x
  in
  begin
    draw_trm g;
    print_endline ((Player.string_of p) ^ "'s turn to play.");
    let rec get_mv () =
    if (Player.mark_of p) = Player.X then ai_ask g else
    let mv = Player.ask_trm p g.n in match mv with
      | Player.Move(r, c) when is_not_legal (r, c) g ->
        (if p.k != Player.AI then print_endline "Illegal move."; get_mv ())
      | _ -> mv
    in match get_mv () with
    | Player.NoMove | Player.Exit -> (print_endline "Bye xo xo!")
    | Player.New -> run (make g.n g.o g.x) 0
    | Player.Move(r, c) -> let g = toggle (r, c) p g in
      match winner_of g with
      | Board.Mark(Player.O) ->
        draw_trm g; print_endline "O wins the game!" ; if retry() then run (make g.n g.o g.x) 0
      | Board.Mark(Player.X) ->
        draw_trm g; print_endline "X wins the game!" ; if retry() then run (make g.n g.o g.x) 0
      | Board.Mark(Player.N) ->
        draw_trm g; print_endline "Nobody wins the game.." ; if retry() then run (make g.n g.o g.x) 0
      | _ -> run g (i + 1)
  end
