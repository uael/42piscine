type 'a tree = Nil | Node of 'a * 'a tree * 'a tree

let rec size = function
| Nil -> 0
| Node(_, l, r) -> 1 + (size l) + (size r)

let rec height = function
| Nil -> 0
| Node(_, l, r) ->
	1 + let ls = size l in let lr = size r in if ls > lr then ls else lr

let draw_tree t =
	let ss = 40 in let sw = ss / 2 in let sh = ss / 4 in
	let rec draw_node x y n =
		match n with
		| Nil -> ()
		| Node(v, l, r) -> begin
			let draw_child d = function
			| Nil -> ()
			| c -> begin
				Graphics.moveto (x + sw) y; Graphics.lineto (x + (ss * 2) - sw) (y + d);
        draw_node (x + (ss * 2)) (y + d) c
			end
			in begin
				Graphics.moveto (x - sw) (y - sh);
        Graphics.lineto (x - sw) (y + sh); Graphics.lineto (x + sw) (y + sh);
        Graphics.lineto (x + sw) (y - sh); Graphics.lineto (x - sw) (y - sh);
        Graphics.moveto (x - sw + 5) (y - 5); Graphics.draw_string v;
				draw_child ((sh * (height l)) *  1) l;
				draw_child ((sh * (height r)) * -1) r;
			end
		end
	in draw_node 30 (((height t) * sh) + 30) t

let () =
	Graphics.open_graph "";
	let t = Node("root",
    Node("l",
      Node("ll", Nil, Node("llr", Nil, Nil)),
      Node("lr", Node("rll", Nil, Nil), Nil)
    ),
    Node("r",
      Node("rl", Node("rll", Nil, Nil), Nil),
      Node("rr", Nil, Node("rrr", Nil, Nil))
    )
  ) in draw_tree t;
	ignore (Graphics.read_key ())
