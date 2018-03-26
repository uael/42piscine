/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 03:31:11 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/24 03:31:13 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_btree.h"

int		btree_level_count(t_btree *root)
{
	int a;
	int b;

	if (root == NULL)
		return (0);
	a = btree_level_count(root->left);
	b = btree_level_count(root->right);
	return (1 + (a > b ? a : b));
}
