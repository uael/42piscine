open Ft_ref

let () =
  let r = return "Hello.." in begin
    print_endline (get r);
    set r "World !";
    print_endline (get r);
    print_endline (get (bind r (fun v -> return ("Hello " ^ v))))
  end
