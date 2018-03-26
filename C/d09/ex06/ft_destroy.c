/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 23:22:01 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/13 23:27:54 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ultimator.h"

void	ft_destroy(char ***factory)
{
	char ***ptr;
	char **ptr2;

	ptr = factory;
	while ((ptr2 = *ptr))
	{
		while (*ptr2)
			free(*ptr2++);
		free(*ptr2);
		free(*ptr++);
	}
	free(*ptr);
	free(factory);
}
