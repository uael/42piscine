/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 02:08:02 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/24 02:08:04 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int		main(int ac, char **av)
{
	char		buff[BUFFS];
	long		rsize;
	unsigned	c;

	rsize = 0;
	if (ac < (int)((c = 0) + 2))
		return (ft_hexdump(0, buff, &rsize, &c));
	if (av[1][0] == '-' && av[1][1] == 'C' && !av[1][2])
	{
		++av;
		--ac;
	}
	return (ft_dump_all(buff, av + 1, ac - 1));
}
