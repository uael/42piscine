/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 02:56:09 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/17 02:56:11 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_list.h"

void	ft_list_swap2(t_list *a, t_list *b)
{
	void *c;

	c = a->data;
	a->data = b->data;
	b->data = c;
}

int		ft_list_size3(t_list *begin_list)
{
	int		s;
	t_list	*node;

	s = 0;
	node = begin_list;
	while (node)
	{
		++s;
		node = node->next;
	}
	return (s);
}

t_list	*ft_list_at2(t_list *begin_list, unsigned int nbr)
{
	int n;

	n = nbr;
	if (begin_list == NULL)
		return (NULL);
	while (n-- && begin_list)
		begin_list = begin_list->next;
	return (n >= -1 ? begin_list : NULL);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int i;

	i = ft_list_size3(begin_list) - 1;
	while (i >= 1)
	{
		ft_list_swap2(begin_list, ft_list_at2(begin_list, (unsigned)i));
		begin_list = begin_list->next;
		i -= 2;
	}
}
