/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 02:53:11 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/17 02:53:13 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list *head;
	t_list *node;

	if (ac < 1)
		return (NULL);
	if ((head = ft_create_elem(av[--ac])) == NULL)
		return (NULL);
	node = head;
	while (ac > 0 && (node->next = ft_create_elem(av[--ac])) != NULL)
		node = node->next;
	return (head);
}
