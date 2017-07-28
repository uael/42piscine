/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 08:03:48 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/14 08:03:50 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void			ft_swap(char **a, char **b)
{
	char *c;

	c = *a;
	*a = *b;
	*b = c;
}

int					ft_compact(char **tab, int length)
{
	int		i;
	int		j;
	int		c;

	if (tab && length > 0)
	{
		i = -1;
		c = 0;
		while (++i < length)
			if (!tab[i])
			{
				j = 1;
				while (i + j < length && !tab[i + j])
					++j;
				if (i + j < length)
				{
					++c;
					ft_swap(tab + i, tab + i + j);
				}
			}
			else
				++c;
		return (c);
	}
	return (length);
}
