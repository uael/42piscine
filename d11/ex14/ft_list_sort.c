/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 02:55:56 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/17 02:55:57 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_list.h"

void	ft_list_swap(t_list *a, t_list *b)
{
	void *c;

	c = a->data;
	a->data = b->data;
	b->data = c;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		swapped;
	t_list	*node;
	t_list	*prev;

	if (begin_list == NULL || *begin_list == NULL || cmp == NULL)
		return ;
	prev = NULL;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		node = *begin_list;
		while (node->next != prev)
		{
			if (cmp(node->data, node->next->data) > 0)
			{
				ft_list_swap(node, node->next);
				swapped = 1;
			}
			node = node->next;
		}
		prev = node;
	}
}
