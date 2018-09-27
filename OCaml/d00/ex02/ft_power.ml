(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_power.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2018/09/27 16:34:10 by alucas-           #+#    #+#             *)
(*   Updated: 2018/09/27 16:41:39 by alucas-          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec ft_power a b =
  if b = 0 then 1 else a * ft_power a (b - 1)

let () =
  print_int (ft_power 2 4); print_char '\n';;
  print_int (ft_power 3 0); print_char '\n';;
  print_int (ft_power 0 5); print_char '\n';;
