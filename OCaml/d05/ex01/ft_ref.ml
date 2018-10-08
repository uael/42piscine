type 'a ft_ref = { mutable v: 'a }

let return x = { v = x }

let get r   = r.v
let set r x = r.v <- x

let bind r f:('b ft_ref) = f r.v
