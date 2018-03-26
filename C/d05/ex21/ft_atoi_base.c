/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 09:17:14 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/06 09:17:16 by alucas-          ###   ########.fr       */
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

int			ft_atoi_base(char *str, char *base)
{
	char	*sptr;
	int		sign;
	int		result;
	int		base_len;
	int		idx;

	if (!str)
		return (0);
	if ((base_len = ft_base_len(base)) == 0)
		return (0);
	while (*str && (*str == ' ' || *str == '\t' || *str == '\r'
		|| *str == '\n' || *str == '\v' || *str == '\f'))
		++str;
	sign = *str == '-' ? -1 : 1;
	if (*str == '+' || sign < 0)
		++str;
	sptr = str;
	while (*sptr)
		if (ft_strchar(base, *sptr++) < 0 && *(sptr - 1) != '-'
			&& *(sptr - 1) != '+')
			return (0);
	result = 0;
	while ((idx = ft_strchar(base, *str++)) >= 0)
		result = result * base_len + idx;
	return (sign * result);
}
