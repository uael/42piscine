/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 02:50:25 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/17 02:50:27 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list *node;

	if ((node = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}
