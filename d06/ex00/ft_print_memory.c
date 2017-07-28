/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 09:17:45 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/06 09:17:47 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char c);

static int	ft_putnbr_base_n(long nbr, char *base, int n)
{
	int i;

	i = 0;
	if (nbr < 0)
	{
		++i;
		ft_putchar('-');
		i += ft_putnbr_base_n(-nbr, base, n);
	}
	else if (nbr < n)
	{
		++i;
		ft_putchar(base[nbr]);
	}
	else
	{
		++i;
		i += ft_putnbr_base_n(nbr / n, base, n);
		ft_putchar(base[nbr % n]);
	}
	return (i);
}

static int	ft_print_memstr(char *ptr, int i, int len)
{
	int		c;

	c = 0;
	if (i++ < len)
	{
		c = ft_putnbr_base_n((int)ptr[i - 1], "0123456789abcdef", 16);
		if (i++ < len)
			c += ft_putnbr_base_n((int)ptr[i - 1], "0123456789abcdef", 16);
	}
	else
		++i;
	while (c < 5)
	{
		ft_putchar(' ');
		++c;
	}
	return (i);
}

static void	ft_print_mem_line(char *ptr, int len)
{
	int		i;

	ft_putnbr_base_n((long)(void *)ptr, "0123456789abcdef", 16);
	ft_putchar(':');
	ft_putchar(' ');
	i = 0;
	while (i < 16)
		i = ft_print_memstr(ptr, i, len);
	i = -1;
	while (++i < 16)
		if (i < len)
			ft_putchar((int)ptr[i] > 31 && (int)ptr[i] != 2032 ? ptr[i] : '.');
	ft_putchar('\n');
}

void		*ft_print_memory(void *addr, unsigned int size)
{
	int		i;
	int		len;

	i = 0;
	while (i < (int)size)
	{
		len = size - i;
		ft_print_mem_line((char *)(addr + i), len > 16 ? 16 : len);
		i += 16;
	}
	return (addr);
}
