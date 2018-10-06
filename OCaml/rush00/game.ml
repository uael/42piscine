type t = { b:Board.t list; o:Player.t; x:Player.t; n:int }

let makeGrid n =
  let rec m = function
  | 0 -> []
  | i -> (Board.make n)::m (i - 1)
  in m (n * n)

let make n po px = { b = makeGrid n; o = po; x = px; n = n }
let copy g b = { b = b; o = g.o; x = g.x; n = g.n }

let is_taken (r, c) g =
  let idx = (((r / g.n) * g.n) + (c / g.n)) in
  let b = List.nth g.b idx in
  Board.isTaken (r mod g.n, c mod g.n) b

let toggle (r, c) p g =
  let idx = (((r / g.n) * g.n) + (c / g.n)) in
  let b = List.mapi
    (fun i e ->
      if i = idx then Board.toggle (r mod g.n, c mod g.n) (Player.mark_of p) e
      else e)
    g.b
  in copy g b

let draw g =
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
    Graphics.clear_graph (); draw g;
    print_endline ((Player.string_of p) ^ "'s turn to play.");
    let rec get_mv () =
      let mv = Player.ask2 p in match mv with
      | Player.Move(r, c) when is_taken (r, c) g ->
        (print_endline "Illegal move."; get_mv ())
      | _ -> mv
    in match get_mv () with
    | Player.Exit -> (print_endline "Bye xo xo!")
    | Player.New -> run (make g.n g.o g.x) 0
    | Player.Move(r, c) -> let g = toggle (r, c) p g in run g (i + 1)
  end
