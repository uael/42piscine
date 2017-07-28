/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 09:16:44 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/06 09:16:45 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int			ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*str++ != '\0')
	{
		++len;
	}
	return (len);
}

unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char *dptr;
	char *sptr;

	dptr = dest;
	sptr = src;
	while (size-- && (*dptr++ = *sptr++) != '\0')
		;
	if (*sptr != '\0')
	{
		*(dptr - 1) = '\0';
		return ((unsigned int)(ft_strlen(src)));
	}
	return (dptr - dest - 1);
}
