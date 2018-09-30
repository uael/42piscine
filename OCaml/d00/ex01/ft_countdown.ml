(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_countdown.ml                                    :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2018/09/27 16:25:30 by alucas-           #+#    #+#             *)
(*   Updated: 2018/09/27 16:30:57 by alucas-          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let ft_countdown x =
  for i = x downto 0 do print_int i; print_char '\n' done

let () =
  ft_countdown 3;
  ft_countdown 0;
  ft_countdown (-1)
