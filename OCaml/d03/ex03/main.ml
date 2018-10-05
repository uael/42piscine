open Btree;;

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
        Graphics.moveto (x - sw + 5) (y - 5);
        Graphics.draw_string (string_of_int v);
        draw_child ((sh * (height l)) *  1) l;
        draw_child ((sh * (height r)) * -1) r;
      end
    end
  in let r_height = function | Nil -> 0 | Node(_, _, r) -> height r
  in draw_node 30 (((1 lsl ((r_height t) - 1)) * sw) + 5) t

let () =
  let t = Node(4,
    Node(2, Node(1, Nil, Nil), Node(3, Nil, Nil)),
    Node(6, Node(5, Nil, Nil), Node(7, Nil, Nil))
  ) in begin
    print_endline (string_of_bool (is_bst t));
    print_endline (string_of_bool (is_perfect t));
  end;
  let t = Node(4,
    Node(2, Node(1, Nil, Nil), Node(0, Nil, Nil)),
    Node(6, Node(5, Nil, Nil), Nil)
  ) in begin
    print_endline (string_of_bool (is_bst t));
    print_endline (string_of_bool (is_perfect t));

    print_endline (string_of_bool (search_bst 2 t));
    print_endline (string_of_bool (search_bst 5 t));
    print_endline (string_of_bool (search_bst 4 t));
    print_endline (string_of_bool (search_bst 7 t));
    print_endline (string_of_bool (search_bst 0 t));
    print_endline (string_of_bool (search_bst 3 t));

  end;
  let t = Node(4,
    Node(2, Node(1, Nil, Nil), Node(3, Nil, Nil)),
    Node(6, Node(5, Nil, Nil), Node(7, Nil, Nil))
  ) in begin
    Graphics.open_graph ""; draw_tree t; ignore (Graphics.read_key ());

    let t = delete_bst 1 t in (
      Graphics.open_graph ""; draw_tree t;
      ignore (Graphics.read_key ());
      let t = delete_bst 7 t in (
        Graphics.open_graph ""; draw_tree t;
        ignore (Graphics.read_key ());
        let t = delete_bst 3 t in (
          Graphics.open_graph ""; draw_tree t;
          ignore (Graphics.read_key ());
          let t = delete_bst 5 t in (
            Graphics.open_graph ""; draw_tree t;
            ignore (Graphics.read_key ());
            let t = add_bst 1 t in (
              Graphics.open_graph ""; draw_tree t;
              ignore (Graphics.read_key ());
              let t = add_bst 7 t in (
                Graphics.open_graph ""; draw_tree t;
                ignore (Graphics.read_key ());
                let t = add_bst 3 t in (
                  Graphics.open_graph ""; draw_tree t;
                  ignore (Graphics.read_key ());
                  let t = add_bst 5 t in (
                    Graphics.open_graph ""; draw_tree t;
                    ignore (Graphics.read_key ())
                  )
                )
              )
            )
          )
        )
      )
    )
  end

