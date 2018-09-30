(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_print_comb.ml                                   :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2018/09/27 16:26:03 by alucas-           #+#    #+#             *)
(*   Updated: 2018/09/27 16:26:05 by alucas-          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let ft_print_comb () =
  let rec comb (x, y, z) = (
    print_int x; print_int y; print_int z;
    match (x, y, z) with
      (7, 8, 9) -> print_string "\n"
    | (_, 8, 9) -> print_string ", "; comb(x + 1, x + 2, x + 3)
    | (_, _, 9) -> print_string ", "; comb(x    , y + 1, y + 2)
    | (_, _, _) -> print_string ", "; comb(x    , y    , z + 1)
  ) in comb(1, 2, 3)

let () =
  ft_print_comb()           
