/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 13:20:39 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/14 13:20:41 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap5(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_integer_table(int *tab, int size)
{
	int imax;
	int i;

	while (--size >= 0)
	{
		i = -1;
		imax = -1;
		while (++i <= size)
			if (imax == -1 || tab[i] > tab[imax])
				imax = i;
		if (imax != size)
			ft_swap5(tab + size, tab + imax);
	}
}

int		ft_unmatch(int *tab, int length)
{
	int i;

	if (tab && length)
	{
		ft_sort_integer_table(tab, length);
		i = -2;
		while ((i += 2) < length)
			if (i + 1 >= length || tab[i] != tab[i + 1])
				return (tab[i]);
	}
	return (0);
}
