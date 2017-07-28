/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 02:56:25 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/17 02:56:27 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_list.h"

void	ft_insert(t_list **h, t_list *p, t_list *node, t_list *n)
{
	n->next = node;
	if (p)
		p->next = n;
	else
		*h = n;
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list *node;
	t_list *new;
	t_list *prev;

	if ((new = ft_create_elem(data)) == NULL || *begin_list == NULL)
	{
		*begin_list = new;
		return ;
	}
	node = *begin_list;
	prev = NULL;
	while (node)
	{
		if (cmp(data, node->data) < 0)
		{
			ft_insert(begin_list, prev, node, new);
			return ;
		}
		prev = node;
		node = node->next;
	}
	(prev ? prev : node)->next = new;
}
