/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 02:53:51 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/17 02:53:56 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	int n;

	n = nbr;
	if (begin_list == NULL)
		return (NULL);
	while (n-- && begin_list)
		begin_list = begin_list->next;
	return (n >= -1 ? begin_list : NULL);
}
