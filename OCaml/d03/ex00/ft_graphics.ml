type 'a tree = Nil | Node of 'a * 'a tree * 'a tree

let draw_square x y size =
	let s = size / 2 in begin
		Graphics.moveto (x - s) (y - s);
		Graphics.lineto (x - s) (y + s);
		Graphics.lineto (x + s) (y + s);
		Graphics.lineto (x + s) (y - s);
		Graphics.lineto (x - s) (y - s)
	end

let draw_tree_node n =
	let ss = 50 in
	let dx = 50 in
	let dy = 100 in
	let draws x y s = begin
		Graphics.moveto (x - ((String.length s / 2) * 10)) (y - 5);
		Graphics.draw_string s
	end in
	match n with
	| Nil -> begin
			draw_square dx dy ss;
			draws dx dy "Nil"
		end
	| Node(v, _, _) -> begin
			draw_square dx dy ss;
      draws dx dy v;

      Graphics.moveto (dx + (ss / 2)) dy;
      Graphics.lineto (dx + 100 - (ss / 2)) (dy + 50);

      draw_square (dx + 100) (dy + 50) ss;
      draws (dx + 100) (dy + 50) "Nil";

      Graphics.moveto (dx + (ss / 2)) dy;
      Graphics.lineto (dx + 100 - (ss / 2)) (dy - 50);

      draw_square (dx + 100) (dy - 50) ss;
      draws (dx + 100) (dy - 50) "Nil";
		end
