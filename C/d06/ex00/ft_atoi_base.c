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

void			ft_putchar(char c);

static int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*str++ != '\0')
	{
		++len;
	}
	return (len);
}

static int		ft_strchar(char *str, char to_find)
{
	char	*sptr;

	sptr = str;
	while (*sptr != '\0')
		if (to_find == *sptr++)
			return ((int)(sptr - str));
	return (0);
}

static int		ft_check_base(char *base, int n)
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

static int		ft_atoi_base_n(char *str, char *base, int sign, unsigned int n)
{
	int		result;

	result = 0;
	while (*str != '\0')
		if (ft_strchar(base, *str) == 0)
			return (sign * result);
		else
			result = result * n + *str++ - '0';
	return (sign * result);
}

int				ft_atoi_base(char *str, char *base)
{
	int		sign;
	int		base_len;

	if (!str)
		return (0);
	while (*str != '\0' &&
		(*str == ' ' || *str == '\t' || *str == '\r' ||
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
	if (base && (base_len = ft_strlen(base)) > 1 &&
		ft_check_base(base, base_len))
		return (ft_atoi_base_n(str, base, sign, (unsigned int)base_len));
	return (0);
}
