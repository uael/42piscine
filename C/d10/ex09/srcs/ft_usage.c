/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 12:13:41 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/13 12:13:43 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "ft_dope.h"
#include "ft_opp.h"

#define STRNSIZE(s) (s),(sizeof(s)-1)

char		*ft_usage(int l, int r, int *out)
{
	t_opp	*opps;
	int		len;
	char	*bptr;

	(void)l;
	(void)r;
	(void)out;
	write(1, STRNSIZE("error : only [ "));
	opps = g_opptab;
	if (opps)
	{
		len = sizeof(g_opptab) / sizeof(*g_opptab);
		while (opps - g_opptab < len)
		{
			bptr = opps->op;
			while (*bptr)
				++bptr;
			write(1, opps->op, bptr - opps->op);
			if (opps - g_opptab < len - 1)
				write(1, " ", 1);
			++opps;
		}
	}
	return ("] are accepted.");
}
