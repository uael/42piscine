class virtual atom name symbol atomic_number =
  object
    val _name = name

    val _symbol = symbol

    val _atomic_number = atomic_number

    method to_string =
      "name: " ^ _name ^ "; symbol: " ^ _symbol ^ "; atomic number: "
      ^ string_of_int _atomic_number

    method equals (a : atom) = a#atomic_number = _atomic_number

    method name = _name

    method symbol = _symbol

    method atomic_number = _atomic_number
  end

class hydrogen =
  object
    inherit atom "hydrogen" "H" 1
  end

class helium =
  object
    inherit atom "helium" "He" 2
  end

class lithium =
  object
    inherit atom "lithium" "Li" 3
  end

class beryllium =
  object
    inherit atom "beryllium" "Be" 4
  end

class boror =
  object
    inherit atom "boror" "B" 5
  end

class carbon =
  object
    inherit atom "carbon" "C" 6
  end

class nitrogen =
  object
    inherit atom "nitrogen" "N" 7
  end

class oxygen =
  object
    inherit atom "oxygen" "O" 8
  end

class fluorine =
  object
    inherit atom "fluorine" "F" 9
  end
