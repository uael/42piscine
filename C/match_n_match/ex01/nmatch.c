/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 05:17:35 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/16 05:17:37 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		nmatch(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		if (*s1)
			return (nmatch(s1 + 1, s2) + nmatch(s1, s2 + 1));
		return (nmatch(s1, s2 + 1));
	}
	if (*s1 == *s2)
	{
		if (*s1)
			return (nmatch(s1 + 1, s2 + 1));
		return (1);
	}
	return (0);
}
