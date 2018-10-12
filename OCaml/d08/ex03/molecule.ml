class virtual molecule name (a_list : Atom.atom list) =
  object
    val _name = name

    val _formula =
      let rec go n str = function
        | [] -> str
        | hd :: nt :: tl when hd#name = nt#name -> go (n + 1) str (nt :: tl)
        | hd :: nt :: tl ->
            go 1
              (str ^ hd#symbol ^ if n > 1 then string_of_int n else "")
              (nt :: tl)
        | hd :: _ -> str ^ hd#symbol ^ if n > 1 then string_of_int n else ""
      in
      go 1 ""
        (List.sort
           (fun x y ->
             match (x#symbol, y#symbol) with
             | a, b when a = b -> 0
             | _, "C" -> 1
             | "C", _ -> -1
             | _, "H" -> 1
             | "H", _ -> -1
             | a, b -> compare a b )
           a_list)

    method name = _name

    method formula = _formula

    method to_string = "name: " ^ _name ^ "; formula: " ^ _formula

    method equals (m : molecule) = m#formula = _formula
  end

class trinitrotoluene =
  object
    inherit
      molecule
        "trinitrotoluene"
        [ new Atom.nitrogen
        ; new Atom.nitrogen
        ; new Atom.nitrogen
        ; new Atom.hydrogen
        ; new Atom.hydrogen
        ; new Atom.hydrogen
        ; new Atom.hydrogen
        ; new Atom.hydrogen
        ; new Atom.oxygen
        ; new Atom.oxygen
        ; new Atom.oxygen
        ; new Atom.oxygen
        ; new Atom.oxygen
        ; new Atom.oxygen
        ; new Atom.carbon
        ; new Atom.carbon
        ; new Atom.carbon
        ; new Atom.carbon
        ; new Atom.carbon
        ; new Atom.carbon
        ; new Atom.carbon ]
  end

class water =
  object
    inherit
      molecule "water" [new Atom.hydrogen; new Atom.hydrogen; new Atom.oxygen]
  end

class carbon_dioxyde =
  object
    inherit
      molecule
        "carbon_dioxyde"
        [new Atom.carbon; new Atom.oxygen; new Atom.oxygen]
  end

class carbon_monoxyde =
  object
    inherit molecule "carbon_monoxyde" [new Atom.carbon; new Atom.oxygen]
  end

class soot =
  object
    inherit molecule "soot" [new Atom.carbon]
  end

class dioxygen =
  object
    inherit molecule "dioxygen" [new Atom.oxygen; new Atom.oxygen]
  end
