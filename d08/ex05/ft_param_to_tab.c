/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 04:49:53 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/09 04:49:57 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#import "ft_stock_par.h"

static char			*ft_strdup(char *src)
{
	char	*dup;
	char	*sptr;
	char	*dptr;

	sptr = src;
	while (*sptr++)
		;
	dup = malloc(sptr - src + 1);
	if (!dup)
		return (NULL);
	dptr = dup;
	while ((*dptr++ = *src++) != '\0')
		;
	return (dup);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	struct s_stock_par	*tab;
	struct s_stock_par	*tptr;
	int					i;
	char				*ptr;

	if ((tab = malloc((ac < 1 ? 1 : ac) * sizeof(t_stock_par))) == NULL)
		return (NULL);
	tptr = tab;
	if (ac > 0 && av != NULL)
	{
		i = -1;
		while (++i < ac)
		{
			if ((ptr = av[i]) == NULL)
				break ;
			while (*ptr++)
				;
			tptr->size_param = (int)(ptr - av[i] - 1);
			tptr->str = av[i];
			tptr->copy = ft_strdup(av[i]);
			tptr++->tab = ft_split_whitespaces(av[i]);
		}
	}
	tptr->str = 0;
	return (tab);
}
