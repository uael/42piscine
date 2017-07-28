/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decrypt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 08:16:44 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/14 08:16:46 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_perso.h"

static int			ft_atoi(char *str)
{
	int		result;
	char	sign;

	if (str == NULL)
		return (0);
	while (*str && (*str == ' ' || (*str >= '\t' && *str <= '\r')))
		++str;
	if ((sign = *str) == '-' || sign == '+')
		++str;
	result = 0;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + *str++ - '0';
	return (sign == '-' ? -result : result);
}

#define PEEK(s) (*(s))
#define NEXT(s) (*(s)++)

t_perso				*ft_perso(char **str)
{
	char	*ptr;
	char	*nptr;
	t_perso	*perso;

	if ((perso = malloc(sizeof(t_perso))) == NULL)
		return (NULL);
	ptr = *str;
	while (PEEK(*str) && NEXT(*str) != '|')
		;
	perso->age = ft_atoi(ptr);
	ptr = *str;
	while (PEEK(ptr) && PEEK(ptr) != ';')
		NEXT(ptr);
	if ((perso->name = malloc(sizeof(char) * (ptr - *str))) == NULL)
		return (NULL);
	nptr = perso->name;
	while (*str < ptr)
		*nptr++ = NEXT(*str);
	*nptr = '\0';
	if (PEEK(*str) == ';')
		NEXT(*str);
	return (perso);
}

t_perso				**ft_decrypt(char *str)
{
	t_perso	**persos;
	char	*ptr;
	int		c;
	int		i;

	ptr = str;
	c = 0;
	while (PEEK(ptr))
		if (NEXT(ptr) == '|')
			++c;
	if ((persos = malloc(sizeof(t_perso) * (c + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < c)
		persos[i++] = ft_perso(&str);
	persos[i] = 0;
	return (persos);
}
