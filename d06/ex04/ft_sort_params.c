/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:13:34 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/08 16:16:46 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

void	ft_swap(char **a, char **b)
{
	char *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		main(int ac, char *av[])
{
	int i;
	int imin;

	while (ac > 1)
	{
		imin = 0;
		i = 0;
		while (++i < ac)
			if (imin == 0 || ft_strcmp(av[i], av[imin]) < 0)
				imin = i;
		while (*av[imin])
			ft_putchar(*av[imin]++);
		ft_putchar('\n');
		if (imin != --ac)
			ft_swap(av + imin, av + ac);
	}
	return (0);
}
