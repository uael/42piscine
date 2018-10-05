type 'a tree = Nil | Node of 'a * 'a tree * 'a tree

let rec height = function
| Nil -> 0
| Node(_, l, r) ->
  1 + let ls = height l in let lr = height r in if ls > lr then ls else lr

let rec is_bst = function
  | Nil -> true
  | Node(i, l, r) ->
    (is_bst l && (match l with
    | Nil -> true
    | Node(j, _, _) -> j < i)) &&
    (is_bst r && (match r with
    | Nil -> true
    | Node(j, _, _) -> j > i))

let rec is_perfect = function
  | Nil -> true | Node(i, Nil, Nil) -> true
  | Node(i, Nil, _) -> false | Node(i, _, Nil) -> false
  | Node(i, l, r) -> (is_perfect l) && (is_perfect r) && (height l) = (height r)
