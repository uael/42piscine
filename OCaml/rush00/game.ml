type t = { b:Board.t list; o:Player.t; x:Player.t; n:int }

let makeGrid n =
  let rec m = function
  | 0 -> []
  | i -> (Board.make n)::m (i - 1)
  in m n

let make n po px = { b = makeGrid n; po; px; n }

let toggle r c p g =
  let idx = (((r / g.n) * g.n) + (c / g.n)) in
  List.mapi
    (fun i e -> if i = idx then Board.toggle (r % g.n) (c % g.n) e else e)
    g.b

let draw g =
  let dx = 0 in let dy = 0 in
  let draw_b
