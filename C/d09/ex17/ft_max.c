/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 11:00:17 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/14 11:00:21 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static inline int	max(int l, int r)
{
	return (l > r ? l : r);
}

int					ft_max(int *tab, int length)
{
	int i;
	int result;

	if (tab && length > 0)
	{
		result = tab[0];
		i = -1;
		while ((i += 2) < length - 1)
			result = max(
				result, i + 1 < length ? max(tab[i], tab[i + 1]) : tab[i]);
	}
	else
		result = 0;
	return (result);
}
