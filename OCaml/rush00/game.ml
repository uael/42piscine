module Player = struct
  type m = X | O | N
  type k = IA | Human
  type t = (m * k * string)

  let string_of_mark = function
  | X -> "X"
  | O -> "O"
  | _ -> "_"

  let string_of_kind = function
  | IA -> "IA"
  | Human -> "Human"

  let name_of = function
  | (_, _, n) -> n

  let string_of = function
  | (m, k, n) -> (string_of_mark m) ^ ": " ^ n ^ " (" (string_of_kind k) ^ ")"

  let ask = function
  | (m, IA, n) -> (0 ,0)
  | (m, Human, n) -> (0 ,0)
end

module Board = struct
  type t = Player.m list

  (* return a new board *)
  let toggle x y p = function
  | [] ->
  | b ->

  let toString b =
end

type t = (Board.t list * (Player.t * Player.t))

(* return a new game *)
let toggle x y p = function
| [] ->
| b ->
