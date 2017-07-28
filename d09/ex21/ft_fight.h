/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 14:10:51 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/14 14:10:53 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FIGHT_H
# define FT_FIGHT_H

# include "ft_perso.h"

# define KICK (15),("judo kick")
# define PUNCH (20),("judo punch")
# define HEADBUTT (15),("judo headbutt")
# define KICK1 (13),("un coup de type 1")
# define KICK2 (3),("un coup de second type")
# define KICK3 (18),("un coup du 3eme type")
# define KICK4 (9),("un coup de type 4")
# define KICK5 (11),("un coup de 5eme type")
# define KICK6 (13),("un coup de sixieme type")
# define KICK7 (8),("un coup de type 7")
# define KICK8 (6),("un tit coup")
# define KICK9 (11),("un coup de type 9")
# define KICK10 (9), ("un coup de type 10")
# define KICK11 (18),("un coup qui fait trop mal")
# define KICK12 (10),("un coup du 12eme type")

void					ft_fight(t_perso *a, t_perso *d, int p, char *c);

#endif
