type 'a tree = Nil | Node of 'a * 'a tree * 'a tree

let rec height = function
| Nil -> 0
| Node(_, l, r) ->
  1 + let ls = height l in let lr = height r in if ls > lr then ls else lr

let rec is_bst = function
| Nil -> true
| Node(i, l, r) ->
  (is_bst l && match l with | Nil -> true | Node(j, _, _) -> j < i) &&
  (is_bst r && match r with | Nil -> true | Node(j, _, _) -> j > i)

let rec is_perfect = function
| Nil | Node(_, Nil, Nil) -> true
| Node(_, Nil, _) | Node(_, _, Nil) -> false
| Node(i, l, r) -> is_perfect l && is_perfect r &&
  height l = height r

let rec is_balanced = function
| Nil -> true
| Node(i, l, r) -> is_balanced l && is_balanced r &&
  abs (height l - height r) <= 1

let rec search_bst v = function
| Nil -> false
| Node(i, l, r) when v = i -> true
| Node(i, l, _) when v < i -> search_bst v l
| Node(i, _, r) -> search_bst v r

let rec add_bst v = function
| Nil -> Node(v, Nil, Nil)
| Node(i, l, r) when v = i -> failwith "invalid operation, you idiot"
| Node(i, l, r) when v < i -> Node(i, add_bst v l, r)
| Node(i, l, r) -> Node(i, l, add_bst v r)

let rec max_bst = function
| Nil -> failwith "invalid operation, you idiot"
| Node (x, _, Nil) -> x
| Node (_, _, r) -> max_bst r

let rec delete_bst v = function
| Nil -> failwith "invalid operation, you idiot"
| Node(i, Nil, Nil) when v = i -> Nil
| Node(i,   l, Nil) when v = i -> l
| Node(i, Nil,   r) when v = i -> r
| Node(i,   l,   r) when v = i -> Node(max_bst l, delete_bst v l, r)
| Node(i,   l,   r) when v < i -> Node(i, delete_bst v l, r)
| Node(i,   l,   r) -> Node(i, l, delete_bst v r)
