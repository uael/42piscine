module Player = struct
  type m = X | O | N
  type k = IA | Human
  type t = (s * k * string)

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
end

module Board = struct
  type t = Player.m list

  let toggle r c  m : Board  = function
  | [] -> raise "no board"
  | b ->
    if ((r > 2) || (r < 0)) || ((c > 2) && (c < 0))
    then raise "Error value"
    else let index = c + (r * 3)

  let toString b =
end

type t = (Board.t list * (Player.t * Player.t))

(* return a new game *)
let toggle x y p = function
| [] ->
| b ->
