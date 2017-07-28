/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 18:13:24 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/13 19:00:07 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

const char	*g_let_me_known[24] =
{
	"THE FOLLOWING TAKES PLACE BETWEEN 12.00 A.M. AND 01.00 A.M.\n",
	"THE FOLLOWING TAKES PLACE BETWEEN 01.00 A.M. AND 02.00 A.M.\n",
	"THE FOLLOWING TAKES PLACE BETWEEN 02.00 A.M. AND 03.00 A.M.\n",
	"THE FOLLOWING TAKES PLACE BETWEEN 03.00 A.M. AND 04.00 A.M.\n",
	"THE FOLLOWING TAKES PLACE BETWEEN 04.00 A.M. AND 05.00 A.M.\n",
	"THE FOLLOWING TAKES PLACE BETWEEN 05.00 A.M. AND 06.00 A.M.\n",
	"THE FOLLOWING TAKES PLACE BETWEEN 06.00 A.M. AND 07.00 A.M.\n",
	"THE FOLLOWING TAKES PLACE BETWEEN 07.00 A.M. AND 08.00 A.M.\n",
	"THE FOLLOWING TAKES PLACE BETWEEN 08.00 A.M. AND 09.00 A.M.\n",
	"THE FOLLOWING TAKES PLACE BETWEEN 09.00 A.M. AND 10.00 A.M.\n",
	"THE FOLLOWING TAKES PLACE BETWEEN 10.00 A.M. AND 11.00 A.M.\n",
	"THE FOLLOWING TAKES PLACE BETWEEN 11.00 A.M. AND 12.00 P.M.\n",
	"THE FOLLOWING TAKES PLACE BETWEEN 12.00 P.M. AND 01.00 P.M.\n",
	"THE FOLLOWING TAKES PLACE BETWEEN 01.00 P.M. AND 02.00 P.M.\n",
	"THE FOLLOWING TAKES PLACE BETWEEN 02.00 P.M. AND 03.00 P.M.\n",
	"THE FOLLOWING TAKES PLACE BETWEEN 03.00 P.M. AND 04.00 P.M.\n",
	"THE FOLLOWING TAKES PLACE BETWEEN 04.00 P.M. AND 05.00 P.M.\n",
	"THE FOLLOWING TAKES PLACE BETWEEN 05.00 P.M. AND 06.00 P.M.\n",
	"THE FOLLOWING TAKES PLACE BETWEEN 06.00 P.M. AND 07.00 P.M.\n",
	"THE FOLLOWING TAKES PLACE BETWEEN 07.00 P.M. AND 08.00 P.M.\n",
	"THE FOLLOWING TAKES PLACE BETWEEN 08.00 P.M. AND 09.00 P.M.\n",
	"THE FOLLOWING TAKES PLACE BETWEEN 09.00 P.M. AND 10.00 P.M.\n",
	"THE FOLLOWING TAKES PLACE BETWEEN 10.00 P.M. AND 11.00 P.M.\n",
	"THE FOLLOWING TAKES PLACE BETWEEN 11.00 P.M. AND 12.00 A.M.\n"
};

void		ft_takes_place(int hour)
{
	write(1, g_let_me_known[hour], 60);
}
