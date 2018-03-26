/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 23:23:38 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/08 23:23:40 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_concat_params(int argc, char **argv)
{
	char	*cat;
	char	*cptr;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (++i < argc && (cptr = argv[i]))
		while (*cptr++)
			++len;
	cat = malloc(len * sizeof(char));
	if (!cat)
		return (NULL);
	cptr = cat;
	i = 0;
	while (++i < argc)
	{
		while (*argv[i])
			*cptr++ = *argv[i]++;
		if (i < argc - 1)
			*cptr++ = '\n';
		else
			*cptr++ = '\0';
	}
	return (cat);
}
