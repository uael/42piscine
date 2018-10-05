type t = Spade | Heart | Diamond | Club

let all = [Spade; Heart; Diamond; Club]

let toString = function
| Spade -> "S"
| Heart -> "H"
| Diamond -> "D"
| Club -> "C"

let toStringVerbose = function
| Spade -> "Spade"
| Heart -> "Heart"
| Diamond -> "Diamond"
| Club -> "Club"
