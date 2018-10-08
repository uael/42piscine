let jokes = [|
  "How many programmers does it take to change a light bulb? None. It's a hardware problem.";
  "Why do programmers always mix up Halloween and Christmas? Because 31 OCT = 25 DEC";
  "What does a proud computer call his little son? A microchip off the old block.";
  "What is another name for a computer virus? A terminal illness";
  "What do you get if you take your computer to an ice rink? A slipped disk";
|]

let () =
  Random.self_init ();
  print_endline (jokes.(Random.int 5))
