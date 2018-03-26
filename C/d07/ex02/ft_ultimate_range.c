/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 23:23:20 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/08 23:23:22 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int *rptr;

	if (min >= max)
		return (0);
	*range = malloc((max - min) * sizeof(int));
	if (!*range)
		return (0);
	rptr = *range;
	while (min < max)
		*rptr++ = min++;
	return ((int)(rptr - *range));
}
