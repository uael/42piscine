/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 14:44:05 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/04 14:44:09 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_comb2(void)
{
	int i;
	int j;

	i = -1;
	while (++i <= 98)
	{
		j = i;
		while (++j <= 99)
		{
			ft_putchar((char)((i / 10) + '0'));
			ft_putchar((char)((i % 10) + '0'));
			ft_putchar(' ');
			ft_putchar((char)((j / 10) + '0'));
			ft_putchar((char)((j % 10) + '0'));
			if (i != 98 || j != 99)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
		}
	}
}
