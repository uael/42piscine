class people n = object
  val name = n
  val hp = 100

  initializer print_endline (name ^ " up!")

  method to_string = "name: " ^ name ^ "; hp: " ^ (string_of_int hp)
  method talk = print_endline ("I'm " ^ name ^ "! Do you know the Doctor?")
  method die = print_endline "Aaaarghh!"
end
