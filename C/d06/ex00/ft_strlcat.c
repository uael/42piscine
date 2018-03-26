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

unsigned int		ft_strlcat(char *dest, char *src, unsigned int size)
{
	char			*ptr;
	char			*sptr;
	unsigned int	space_left;
	unsigned int	len;

	ptr = dest;
	sptr = src;
	space_left = size;
	while (space_left-- && *ptr != '\0')
		ptr++;
	len = ptr - dest;
	space_left = size - len;
	if (space_left == 0)
		return (len + ft_strlen(sptr));
	while (*sptr != '\0')
	{
		if (space_left > 1)
		{
			*ptr++ = *sptr;
			--space_left;
		}
		sptr++;
	}
	*ptr = '\0';
	return (len + (sptr - src));
}
