let rec hfs_f = function
    n when n < 0 -> -1
  | 0 -> 1
  | n -> n - hfs_m (hfs_f (n - 1))
and hfs_m = function
    n when n < 0 -> -1
  | 0 -> 0
  | n -> n - hfs_f (hfs_m (n - 1))

let () =
  print_int(hfs_m 0); print_char '\n';
  print_int(hfs_f 0); print_char '\n';
  print_int(hfs_m 4); print_char '\n';
  print_int(hfs_f 4); print_char '\n'
