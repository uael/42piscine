open Ft_graphics;;

let () =
	Graphics.open_graph "";
	if Graphics.read_key () = 'n' then
		draw_tree_node (Nil)
	else
		draw_tree_node (Node ("Lul", Nil, Nil));
	ignore (Graphics.read_key ())
