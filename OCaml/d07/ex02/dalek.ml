class dalek = object(self)
  val hp = 100
  val name = "Dalek"
    ^ String.make 1 (char_of_int ((Random.int 26) + 65))
    ^ String.make 1 (char_of_int ((Random.int 26) + 97))
    ^ String.make 1 (char_of_int ((Random.int 26) + 97))
  val mutable shield = true

  method talk =
    let t = function
		| 0  -> "Explain! Explain!"
	  | 1  -> "Exterminate! Exterminate!"
	  | 2  -> "I obey!"
	  | _  -> "You are the Doctor! You are the enemy of the Daleks!"
	  in print_endline (t (Random.int 3))

  method to_string =
    "name: " ^ name ^ "; shield: " ^ (string_of_bool shield)
    ^ "; hp: " ^ (string_of_int hp)

  method exterminate (p: People.people) =
    p#die

  method die = print_endline "Emergency Temporal Shift!"

end