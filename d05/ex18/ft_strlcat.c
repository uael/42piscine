/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 09:16:29 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/06 09:16:31 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*str++ != '\0')
		++len;
	return (len);
}

int			ft_strnlen(char *str, unsigned size)
{
	unsigned len;

	len = 0;
	while (len < size && *str)
	{
		++len;
		++str;
	}
	return (len);
}

char		*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		*(dest + i) = *(src + i);
		++i;
	}
	while (i < n)
		*(dest + i++) = '\0';
	return (dest);
}

unsigned	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned slen;
	unsigned dlen;

	slen = ((unsigned)ft_strlen(src));
	dlen = ((unsigned)ft_strnlen(dest, size));
	if (dlen == size)
		return (size + slen);
	if (slen < size - dlen)
		ft_strncpy(dest + dlen, src, slen + 1);
	else
	{
		ft_strncpy(dest + dlen, src, size - dlen - 1);
		dest[size - 1] = '\0';
	}
	return (dlen + slen);
}
