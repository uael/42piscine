/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 09:15:37 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/06 09:15:39 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprintable(int c)
{
	return (c > 31 && c < 127);
}

int		ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (ft_isprintable(*str) == 0)
			return (0);
		++str;
	}
	return (1);
}
