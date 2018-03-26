/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 12:05:02 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/13 12:05:04 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_opp.h"

t_opp		*ft_opp(char *op)
{
	t_opp	*opps;
	int		len;

	if (op == NULL)
		return (NULL);
	opps = g_opptab;
	if (opps == NULL)
		return (NULL);
	len = sizeof(g_opptab) / sizeof(*g_opptab);
	while (opps->op && opps - g_opptab < len)
		if (ft_strcmp(op, opps->op) == 0)
			return (opps);
		else
			++opps;
	return (NULL);
}
