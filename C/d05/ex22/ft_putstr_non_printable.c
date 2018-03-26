/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 09:17:27 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/06 09:17:29 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char c);

int			ft_strchar(char *str, char to_find)
{
	char	*sptr;

	sptr = str;
	while (*sptr != '\0')
		if (to_find == *sptr++)
			return ((int)(sptr - str - 1));
	return (-1);
}

int			ft_base_len(char *base)
{
	char	*sptr;
	int		base_len;
	int		n;

	if (!base)
		return (0);
	sptr = base;
	while (*sptr++)
		;
	if ((base_len = ((int)(sptr - base - 1))) <= 1)
		return (0);
	n = -1;
	while (++n < base_len)
	{
		if (base[n] == '+' || base[n] == '-')
			return (0);
		if (base[n] < 32 || base[n] > 126)
			return (0);
		if (ft_strchar(base + n + 1, base[n]) >= 0)
			return (0);
	}
	return (base_len);
}

void		ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	char	buffer[5000];
	int		i;
	int		neg;

	if ((base_len = ft_base_len(base)) > 1)
	{
		i = 0;
		neg = 0;
		if (nbr < 0)
		{
			nbr = -nbr;
			neg = 1;
		}
		while (nbr >= base_len)
		{
			buffer[++i] = base[nbr % base_len];
			nbr /= base_len;
		}
		buffer[++i] = base[nbr % base_len];
		if (neg)
			buffer[++i] = '-';
		while (i)
			ft_putchar(buffer[i--]);
	}
}

void		ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str < 32 || *str > 126)
		{
			ft_putchar('\\');
			if (*str < 16)
				ft_putchar('0');
			ft_putnbr_base((int)*str, "0123456789abcdef");
		}
		else
			ft_putchar(*str);
		++str;
	}
}
