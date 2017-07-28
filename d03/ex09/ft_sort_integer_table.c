/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 08:24:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/05 08:24:33 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
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

	if (tab)
		while (--size >= 0)
		{
			i = -1;
			imax = -1;
			while (++i <= size)
				if (imax == -1 || tab[i] > tab[imax])
					imax = i;
			if (imax != size)
				ft_swap(tab + size, tab + imax);
		}
}
