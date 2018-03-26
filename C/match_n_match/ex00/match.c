/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 05:22:47 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/16 05:22:49 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		match(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		if (*s1)
			return (match(s1 + 1, s2) || match(s1, s2 + 1));
		return (match(s1, s2 + 1));
	}
	if (*s1 == *s2)
	{
		if (*s1)
			return (match(s1 + 1, s2 + 1));
		return (1);
	}
	return (0);
}