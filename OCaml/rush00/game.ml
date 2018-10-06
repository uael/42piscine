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
