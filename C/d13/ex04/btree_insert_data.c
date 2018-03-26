/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 09:36:12 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/20 09:36:14 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *i, int (*cmpf)(void *, void *))
{
	t_btree **loc;

	if (root == NULL)
		return ;
	loc = root;
	while (*loc)
		loc = cmpf(i, (*loc)->item) < 0 ? &(*loc)->left : &(*loc)->right;
	*loc = btree_create_node(i);
}
