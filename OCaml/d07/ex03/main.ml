let () =
  let da = new Dalek.dalek in
  let pe = new People.people "Malou" in
  let dr = new Doctor.doctor "Malou+" 999 pe in
  let da_army = new Army.army [da] in
  let dr_army = new Army.army [dr] in
  let pe_army = new Army.army [pe] in
  let da_army = da_army#add da in
  let dr_army = dr_army#add dr in
  let pe_army = pe_army#add pe in
  if dr_army#get_crew != [] && da_army#get_crew != [] && pe_army#get_crew != []
  then print_endline "Army up";
  let dr_army = dr_army#delete in
  let dr_army = dr_army#delete in
  let da_army = da_army#delete in
  let da_army = da_army#delete in
  let pe_army = pe_army#delete in
  let pe_army = pe_army#delete in
  if dr_army#get_crew = [] && da_army#get_crew = [] && pe_army#get_crew = []
  then print_endline "Army down"
