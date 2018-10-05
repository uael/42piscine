type 'a tree = Nil | Node of 'a * 'a tree * 'a tree

let rec size = function
| Nil -> 0
| Node(_, l, r) -> 1 + (size l) + (size r)

let rec height = function
| Nil -> 0
| Node(_, l, r) -> 1 +
	let ls = size l in
	let lr = size r in
	if ls > lr then ls else lr

let draw_square x y size =
	let w = size / 2 in
	let h = size / 4 in begin
		Graphics.moveto (x - w) (y - h);
		Graphics.lineto (x - w) (y + h); Graphics.lineto (x + w) (y + h);
		Graphics.lineto (x + w) (y - h); Graphics.lineto (x - w) (y - h)
	end

let ss = 40

let draw_tree t =
	let rec draw_tree_node dx dy n =
		let draws x y s = begin
			draw_square dx dy ss;
			Graphics.moveto (x - (ss / 2) + 5) (y - 5); Graphics.draw_string s
		end in
		match n with
		| Nil -> ()
		| Node(v, l, r) -> begin
			let draw_child y = function
			| Nil -> ()
			| c -> begin
					Graphics.moveto (dx + (ss / 2)) dy;
          Graphics.lineto (dx + (ss * 2) - (ss / 2)) (dy + y);
          draw_tree_node (dx + (ss * 2)) (dy + y) c
				end
			in begin
				draws dx dy v;
				draw_child (((ss / 4) * (height l)) *  1) l;
				draw_child (((ss / 4) * (height r)) * -1) r;
			end
		end
	in let rec pretty_height = function
	| Nil -> 0
	| Node(_, _, r) -> (1 + (height r))
	in draw_tree_node 30 (((pretty_height t) * 20) + 10) t

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
