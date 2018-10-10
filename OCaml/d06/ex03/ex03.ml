module type FIXED = sig
  type t
  val of_float  : float -> t
  val of_int    : int -> t
  val to_float  : t -> float
  val to_int    : t -> int
  val to_string : t -> string
  val zero : t
  val one  : t
  val succ : t -> t
  val pred : t -> t
  val min  : t -> t -> t
  val max  : t -> t -> t
  val gth  : t -> t -> bool
  val lth  : t -> t -> bool
  val gte  : t -> t -> bool
  val lte  : t -> t -> bool
  val eqp  : t -> t -> bool (** physical equality *)
  val eqs  : t -> t -> bool (** structural equality *)
  val add  : t -> t -> t
  val sub  : t -> t -> t
  val mul  : t -> t -> t
  val div  : t -> t -> t
  val foreach : t -> t -> (t -> unit) -> unit
end

module type FRACTIONNAL_BITS = sig val bits : int end

module type MAKE = functor (Fb: FRACTIONNAL_BITS) -> FIXED

module Make : MAKE = functor (Fb: FRACTIONNAL_BITS) -> struct
  type t = int
  let of_float f = int_of_float
    (floor (f *. float_of_int (1 lsl Fb.bits) +. 0.5))
  let of_int i = i lsl Fb.bits
  let to_float fb = float_of_int fb /. float_of_int (1 lsl Fb.bits)
  let to_int fb = fb lsr Fb.bits
  let to_string fb = string_of_float (to_float fb)
  let zero = 0
  let one  = 1 lsl Fb.bits
  let succ fb = fb + 1
  let pred fb = fb - 1
  let min a b = if a <= b then a else b
  let max a b = if a >= b then a else b
  let gth a b = a > b
  let lth a b = a < b
  let gte a b = a >= b
  let lte a b = a <= b
  let eqp a b = a == b
  let eqs a b = a = b
  let add a b = a + b
  let sub a b = a - b
  let mul a b = (a * b + (1 lsl Fb.bits - 1)) lsr (1 lsl Fb.bits)
  let div a b =
    let f = (a lsl Fb.bits) in
    if (f >= 0 && b >= 0) || (f < 0 && b < 0)
    then (f + b / 2) / b else (f - b / 2) / b
  let foreach a b f =
    let rec go x =
    if x <= b then (f x; go (x + 1))
    in go a
end

module Fixed4 : FIXED = Make (struct let bits = 4 end)
module Fixed8 : FIXED = Make (struct let bits = 8 end)

let () =
  let x8 = Fixed8.of_float 21.10 in
  let y8 = Fixed8.of_float 21.32 in
  let r8 = Fixed8.add x8 y8 in
  print_endline (Fixed8.to_string r8);
  Fixed4.foreach (Fixed4.zero) (Fixed4.one)
    (fun f -> print_endline (Fixed4.to_string f));
  print_endline (string_of_float (Fixed8.to_float (Fixed8.of_float 42.21)));
  print_endline (string_of_int (Fixed8.to_int (Fixed8.of_int 42)));
  print_endline (Fixed8.to_string (Fixed8.of_float 42.21));
  print_endline (Fixed8.to_string Fixed8.zero);
  print_endline (Fixed8.to_string Fixed8.one);
  print_endline (Fixed8.to_string (Fixed8.succ Fixed8.one));
  print_endline (Fixed8.to_string (Fixed8.pred Fixed8.one));
  print_endline (Fixed8.to_string (Fixed8.min Fixed8.zero Fixed8.one));
  print_endline (Fixed8.to_string (Fixed8.max Fixed8.zero Fixed8.one));
  print_endline (string_of_bool (Fixed8.gth Fixed8.zero Fixed8.one));
  print_endline (string_of_bool (Fixed8.lth Fixed8.zero Fixed8.one));
  print_endline (string_of_bool (Fixed8.gte Fixed8.zero Fixed8.one));
  print_endline (string_of_bool (Fixed8.lte Fixed8.zero Fixed8.one));
  print_endline (string_of_bool (Fixed8.eqp Fixed8.zero Fixed8.one));
  print_endline (string_of_bool (Fixed8.eqs Fixed8.zero Fixed8.one));
  print_endline (Fixed8.to_string (Fixed8.add Fixed8.zero Fixed8.one));
  print_endline (Fixed8.to_string (Fixed8.sub Fixed8.zero Fixed8.one));
  print_endline (Fixed8.to_string (Fixed8.mul Fixed8.zero Fixed8.one));
  print_endline (Fixed8.to_string (Fixed8.div Fixed8.zero Fixed8.one))
