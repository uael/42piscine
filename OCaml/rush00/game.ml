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

let rec run g i =
  let p = match i with
    | i when (i mod 2) = 0 -> g.o
    | i -> g.x
  in begin
    draw_trm g;
    print_endline ((Player.string_of p) ^ "'s turn to play.");
    let rec get_mv () =
      let mv = Player.ask_trm p in match mv with
      | Player.Move(r, c) when is_not_legal (r, c) g ->
        (print_endline "Illegal move."; get_mv ())
      | _ -> mv
    in match get_mv () with
    | Player.Exit -> (print_endline "Bye xo xo!")
    | Player.New -> run (make g.n g.o g.x) 0
    | Player.Move(r, c) -> let g = toggle (r, c) p g in
      run g (i + 1)
  end
