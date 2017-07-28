/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 12:49:01 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/14 12:49:04 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef unsigned long	t_ulong;

static inline t_ulong	ft_strlen2(char *s)
{
	char *sptr;

	sptr = s;
	while (*sptr)
		++sptr;
	return (sptr - s);
}

void					ft_join_in(char **tab, char *sep, char *result)
{
	char	*sptr;

	while (*tab)
	{
		while (**tab)
			*result++ = *((*tab)++);
		if (*++tab)
		{
			sptr = sep;
			while (*sptr)
				*result++ = *sptr++;
		}
	}
	*result = '\0';
}

char					*ft_join(char **tab, char *sep)
{
	t_ulong len;
	t_ulong slen;
	char	*result;
	char	**tptr;

	if (tab == NULL)
		return (NULL);
	if (sep == (void *)(len = 0))
	{
		slen = 0;
		sep = "";
	}
	else
		slen = ft_strlen2(sep);
	tptr = tab;
	while (*tptr)
	{
		len += ft_strlen2(*tptr) + slen;
		++tptr;
	}
	len -= slen - 1;
	if ((result = malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	ft_join_in(tab, sep, result);
	return (result);
}
