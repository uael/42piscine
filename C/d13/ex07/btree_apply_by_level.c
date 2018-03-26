/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 03:49:09 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/24 03:49:10 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_btree.h"

typedef void	(*t_applyf)(void*, int, int);

int		btree_apply_to_lvl(t_btree *root, int lvl, int pos, void *data[2])
{
	int p;

	if (root == NULL)
		return (0);
	if (lvl != 0)
	{
		p = btree_apply_to_lvl(root->left, lvl - 1, pos, data);
		p += btree_apply_to_lvl(root->right, lvl - 1, p, data);
		return (p);
	}
	((t_applyf)data[1])(root->item, *((int *)data[0]), pos == 0);
	return (pos + 1);
}

int		btree_level_count2(t_btree *root)
{
	int a;
	int b;

	if (root == NULL)
		return (0);
	a = btree_level_count2(root->left);
	b = btree_level_count2(root->right);
	return (1 + (a > b ? a : b));
}

void	btree_apply_by_level(t_btree *root, t_applyf applyf)
{
	int c;
	int i;

	c = btree_level_count2(root);
	i = -1;
	while (++i < c)
		btree_apply_to_lvl(root, i, 0, (void *[2]){&i, applyf});
}
