open Gardening;;

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
  ) in Gardening.draw_tree t;
  ignore (Graphics.read_key ())
