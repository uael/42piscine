/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 23:24:48 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/08 23:24:50 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strchar(char to_find, char *str)
{
	char	*sptr;

	sptr = str;
	while (*sptr != '\0')
		if (to_find == *sptr++)
			return (1);
	return (0);
}

static int	ft_wc(char *str, char *charset)
{
	int		i;

	i = 0;
	while (*str)
		if (ft_strchar(*str, charset))
			++str;
		else
		{
			++i;
			++str;
			while (*str && !ft_strchar(*str, charset))
				++str;
		}
	return (i);
}

static char	*ft_split_w(char **str, char *charset)
{
	char	*bptr;
	char	*bsptr;
	char	*sptr;

	sptr = *str;
	while (ft_strchar(*sptr, charset))
		++sptr;
	*str = sptr;
	while (!ft_strchar(*sptr, charset))
		++sptr;
	bptr = malloc(sptr - *str);
	if (!bptr)
		return (NULL);
	bsptr = bptr;
	while (sptr > *str)
		*bsptr++ = *((*str)++);
	*bsptr = '\0';
	while (**str && ft_strchar(**str, charset))
		++*str;
	return (bptr);
}

char		**ft_split(char *str, char *charset)
{
	char	**buffer;
	char	**bptr;
	int		i;

	i = ft_wc(str, charset);
	if (!(buffer = malloc((i + 1) * sizeof(char *))))
		return (NULL);
	bptr = buffer;
	while (i--)
		if (!(*bptr++ = ft_split_w(&str, charset)))
			return (NULL);
	*bptr = (NULL);
	return (buffer);
}
