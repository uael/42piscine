(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_print_alphabet.ml                               :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2018/09/27 16:52:54 by alucas-           #+#    #+#             *)
(*   Updated: 2018/09/27 17:01:30 by alucas-          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let ft_print_alphabet () =
  for c = int_of_char 'a' to int_of_char 'z' do print_char (char_of_int c) done;
  print_char '\n'

let () =
  ft_print_alphabet()

