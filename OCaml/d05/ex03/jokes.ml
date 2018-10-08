let jokes = [|
  "How many programmers does it take to change a light bulb? None. It's a hardware problem.";
  "Why do programmers always mix up Halloween and Christmas? Because 31 OCT = 25 DEC";
  "What does a proud computer call his little son? A microchip off the old block.";
  "What is another name for a computer virus? A terminal illness";
  "What do you get if you take your computer to an ice rink? A slipped disk";
|]

let read f =
  let ic = open_in f in
  let ln = input_line ic in
  let len = String.length ln in
  let cnt = ref 0 in
  for i = 0 to len - 1 do if ln.[i] = ';' then incr cnt done in
  let a = (Array.make len "") in

  close_in ic

let () =
  Random.self_init ();
  print_endline (jokes.(Random.int 5))
