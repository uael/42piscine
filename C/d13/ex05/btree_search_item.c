/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 11:27:06 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/20 11:27:30 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *d, int (*cmpf)(void *, void *))
{
	int cmp;

	if (root == NULL || cmpf == NULL)
		return (NULL);
	if ((cmp = cmpf(root->item, d)) == 0)
		return (root->item);
	if (cmp > 0)
		return (btree_search_item(root->left, d, cmpf));
	return (btree_search_item(root->right, d, cmpf));
}
