class doctor n a s = object (self)
  val name: string = n
  val age: int = a
  val sidekick: People.people = s
  val mutable hp = 100

  initializer print_endline (name ^ " up!")

  method to_string = "name: " ^ name ^ "; age: " ^ (string_of_int age) ^
    "; sidekick: " ^ (sidekick#to_string) ^ "; " ^ (string_of_int hp)

  method talk = "Hi! I’m the Doctor!"

  method travel_in_time start arrival =
	print_endline ("       ___
       | |
       | |
-------------------
-------------------
|  ___  |  ___  |
| | | | | | | | |
| |-+-| | |-+-| |
| |_|_| | |_|_| |
|  ___  |  ___  |
| |   | | |   | |
| |   | | |   | |
| |___| | |___| |
|  ___  |  ___  |
| |   | | |   | |
| |   | | |   | |
| |___| | |___| |
|       |       |
===================
from " ^ (string_of_int start) ^ " to " ^ (string_of_int arrival))

  method use_sonic_screwdriver =
    print_endline "Whiiiiwhiiiwhiii Whiiiiwhiiiwhiii Whiiiiwhiiiwhiii"

  method private regenerate =
    print_endline "I'm back, inf+ life left";
    hp <- 100

  method kick x =
    print_endline "Oh don't touch me, you idiot!";
    hp <- hp - x;
    if hp <= 0 then self#die

  method die =
    print_endline "Aaaarghh!";
    self#regenerate
end
