/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 02:55:42 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/17 02:55:44 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *node;

	if (begin_list1 == NULL)
		return ;
	if (*begin_list1 == NULL)
		*begin_list1 = begin_list2;
	else
	{
		node = *begin_list1;
		while (node->next)
			node = node->next;
		node->next = begin_list2;
	}
}
