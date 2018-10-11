class ['a] army (c: 'a list) = object(self)
  val crew = c

  method add e = new army (e::crew)
  method delete = new army (List.tl crew)
  method get_crew = crew
end
