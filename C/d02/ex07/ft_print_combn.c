/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 07:23:20 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/05 07:23:28 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char c);

static int	ft_combn_buffer(char *buffer, int nbr, int n)
{
	int		i;

	i = 0;
	while (nbr >= 10)
	{
		buffer[i++] = (char)((nbr % 10) + '0');
		nbr /= 10;
	}
	buffer[i] = (char)((nbr % 10) + '0');
	while (i < n)
		buffer[++i] = '0';
	i = 0;
	while (++i < n)
		if (buffer[i - 1] <= buffer[i])
			return (0);
	return (1);
}

void		ft_print_combn(int n)
{
	char	buffer[n - 1];
	int		i;
	int		j;
	int		k;

	if (n < 1 || n > 9)
		return ;
	k = n;
	j = 9 - n + 1;
	i = 0;
	while (--k >= 0)
		i = i * 10 + j++;
	j = 1;
	while (j <= i)
		if (ft_combn_buffer(buffer, j++, n) && (k = n - 1))
		{
			while (k >= 0)
				ft_putchar(buffer[k--]);
			if (j < i)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
		}
}
