let get_name = function
  | 1 -> "methane"
  | 2 -> "ethane"
  | 3 -> "propane"
  | 4 -> "butane"
  | 5 -> "pentane"
  | 6 -> "hexane"
  | 7 -> "heptane"
  | 8 -> "octane"
  | 9 -> "nonane"
  | _ -> invalid_arg "you idiot"

let get_atoms x =
  let make_atoms atom n =
    let rec go i l = if i = 0 then l else go (i - 1) (atom :: l) in
    go n []
  in
  make_atoms (new Atom.carbon) x @ make_atoms (new Atom.hydrogen) ((2 * x) + 2)

class virtual alkane n =
  object
    inherit Molecule.molecule (get_name n) (get_atoms n)

    val _c = n

    val _h = (2 * n) + 2

    method get_c = _c

    method get_h = _h
  end

class methane =
  object
    inherit alkane 1
  end

class ethane =
  object
    inherit alkane 2
  end

class propane =
  object
    inherit alkane 3
  end

class butane =
  object
    inherit alkane 4
  end

class pentane =
  object
    inherit alkane 5
  end

class hexane =
  object
    inherit alkane 6
  end

class heptane =
  object
    inherit alkane 7
  end

class octane =
  object
    inherit alkane 8
  end

class nonane =
  object
    inherit alkane 9
  end
