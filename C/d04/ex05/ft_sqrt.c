/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 11:53:41 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/05 11:53:43 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int result;

	result = 1;
	while (result * result <= nb)
	{
		if (result * result == nb)
			return (result);
		++result;
	}
	return (0);
}
