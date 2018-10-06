type t = { b:Board.t list; o:Player.t; x:Player.t; n:int }

let makeGrid n =
  let rec m = function
  | 0 -> []
  | i -> (Board.make n)::m (i - 1)
  in m n

let make n po px = { b = makeGrid n; o = po; x = px; n = n }

let toggle (r, c) p g =
  let idx = (((r / g.n) * g.n) + (c / g.n)) in
  List.mapi
    (fun i e -> if i = idx then Board.toggle (r mod g.n, c mod g.n) p.m e else e)
    g.b

let draw g =
  let rec draw_b i = function
  | [] -> ()
  | b::t -> begin
    let x = i mod g.n in let y = g.n - (i / g.n) in
    Board.draw (x * (g.n * 20)) (y * (g.n * 20)) b;
    draw_b (i + 1) t
  end in draw_b 0 g.b

let run g =
  let rec loop i =
    let p = match i with
      | i when i mod 2 -> g.o
      | i -> g.x
    in let mv = Player.ask p in begin
      toggle mv p g;
      draw g;
      loop (i + 1)
    end
  in loop 0
