/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 02:56:43 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/17 02:56:54 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_list.h"

t_list	*ft_sorted_merge(t_list *a, t_list *b, int (*cmp)())
{
	if (a == NULL)
		return (b);
	if (b == NULL)
		return (a);
	if (cmp(a->data, b->data) < 0)
	{
		a->next = ft_sorted_merge(a->next, b, cmp);
		return (a);
	}
	b->next = ft_sorted_merge(b->next, a, cmp);
	return (b);
}

void	ft_sorted_list_merge(t_list **a, t_list *b, int (*cmp)())
{
	t_list *head;

	if (cmp && a)
	{
		if ((head = *a) == NULL)
			head = b;
		else if (b)
		{
			if (cmp(head->data, b->data) > 0)
				head = b;
			ft_sorted_merge(*a, b, cmp);
		}
		*a = head;
	}
}
