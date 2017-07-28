/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 09:04:00 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/13 09:04:10 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			*ft_map(int *tab, int length, int (*f)(int))
{
	int		*buffer;
	int		i;

	buffer = NULL;
	if (tab)
	{
		if (length <= 0)
			return (buffer);
		if ((buffer = malloc(sizeof(int) * length)) == NULL)
			return (buffer);
		i = -1;
		while (++i < length)
			buffer[i] = f ? f(tab[i]) : tab[i];
	}
	return (buffer);
}
