/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 18:26:01 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/23 18:26:04 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int		main(int ac, char **av)
{
	t_opts	opts;
	long	r;
	char	buff[BUFFS];

	if ((r = ft_tail_opts(&opts, ac, av)) != 0)
		return ((int)r);
	if (!opts.files)
		while ((r = read(0, buff, BUFFS)) != 0 && r != -1)
			;
	return (ft_tail(&opts));
}
