/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 09:17:00 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/06 09:17:02 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char c);

static int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*str++ != '\0')
	{
		++len;
	}
	return (len);
}

static void	ft_putnbr_base_n(int nbr, char *base, int n)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		if (nbr == -2147483648)
		{
			ft_putnbr_base_n(2, base, n);
			ft_putnbr_base_n(147483648, base, n);
		}
		else
			ft_putnbr_base_n(-nbr, base, n);
	}
	else if (nbr < n)
		ft_putchar(base[nbr]);
	else
	{
		ft_putnbr_base_n(nbr / n, base, n);
		ft_putchar(base[nbr % n]);
	}
}

static int	ft_strchar(char *str, char to_find)
{
	while (*str != '\0')
		if (to_find == *str++)
			return (1);
	return (0);
}

static int	ft_check_base(char *base, int n)
{
	while (n)
	{
		if (base[n] == '+' || base[n] == '-')
			return (0);
		if (ft_strchar(base + n + 1, base[n]))
			return (0);
		--n;
	}
	return (1);
}

void		ft_putnbr_base(int nbr, char *base)
{
	int		base_len;

	if (base && (base_len = ft_strlen(base)) > 1 &&
		ft_check_base(base, base_len))
		ft_putnbr_base_n(nbr, base, base_len);
}
