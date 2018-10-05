open Btree;;

let () =
  let t = Node(4,
    Node(2, Node(1, Nil, Nil), Node(3, Nil, Nil)),
    Node(6, Node(5, Nil, Nil), Node(7, Nil, Nil))
  ) in begin
    print_endline (string_of_bool (is_bst t));
    print_endline (string_of_bool (is_perfect t))
  end

