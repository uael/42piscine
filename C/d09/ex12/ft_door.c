/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 07:43:05 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/14 07:43:08 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_door.h"

void		ft_putstr(char *str)
{
	unsigned i;

	i = 0;
	while (str[i])
		++i;
	write(1, str, i);
}

void		open_door(t_door *door)
{
	ft_putstr("Door opening...\n");
	door->state = OPEN;
}

void		close_door(t_door *door)
{
	ft_putstr("Door closing...\n");
	door->state = CLOSE;
}

t_bool		is_door_open(t_door *door)
{
	ft_putstr("Door is open ?\n");
	return ((t_bool)(door->state == OPEN));
}

t_bool		is_door_close(t_door *door)
{
	ft_putstr("Door is close ?\n");
	return ((t_bool)(door->state == CLOSE));
}
