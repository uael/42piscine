/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 08:23:49 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/05 08:23:50 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_swap(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

char		*ft_strrev(char *str)
{
	char	*begin;
	char	*end;

	begin = str;
	end = str;
	while (*end != '\0')
	{
		end++;
	}
	end--;
	while (begin < end)
	{
		ft_swap(begin, end);
		begin++;
		end--;
	}
	return (str);
}
