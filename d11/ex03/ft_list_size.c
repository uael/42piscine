/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 02:52:19 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/17 02:52:21 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
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
