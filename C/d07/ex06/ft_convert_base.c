/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 23:24:32 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/08 23:24:34 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strchar(char *str, char to_find)
{
	char	*sptr;

	sptr = str;
	while (*sptr != '\0')
		if (to_find == *sptr++)
			return ((int)(sptr - str));
	return (0);
}

static int	ft_atoi_base_n(char *str, char *base, int base_len)
{
	int		result;
	int		sign;
	int		idx;

	while (*str != '\0' && (*str == ' ' || *str == '\t' || *str == '\r' ||
		*str == '\n' || *str == '\v' || *str == '\f'))
		++str;
	sign = 1;
	if (*str == '+')
		++str;
	else if (*str == '-')
	{
		++str;
		sign = -1;
	}
	result = 0;
	while (*str != '\0')
		if ((idx = ft_strchar(base, *str++)) == 0)
			return (-1);
		else
			result = result * base_len + idx - 1;
	return (sign * result);
}

static int	ft_putnbr_base_n(char *buffer, int nbr, const char *base, int n)
{
	int		i;
	char	neg;

	i = 0;
	neg = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		neg = 1;
	}
	while (nbr >= n)
	{
		buffer[i++] = base[nbr % n];
		nbr /= n;
	}
	buffer[i++] = base[nbr % n];
	if (neg)
		buffer[i++] = '-';
	return (i - 1);
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	buffer[4096];
	char	*ptr;
	char	*sptr;
	int		i;

	sptr = base_from;
	while (*sptr++)
		;
	if ((i = ft_atoi_base_n(nbr, base_from, sptr - base_from - 1)) < 0)
		return ((char *)0);
	sptr = base_to;
	while (*sptr++)
		;
	i = ft_putnbr_base_n(buffer, i, base_to, (int)(sptr - base_to - 1));
	ptr = malloc(i + 1);
	if (!ptr)
		return ((char *)0);
	sptr = ptr;
	while (i >= 0)
		*sptr++ = buffer[i--];
	*sptr = '\0';
	return (ptr);
}
