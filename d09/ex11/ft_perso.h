/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 07:36:05 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/14 07:36:07 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PERSO_H
# define FT_PERSO_H

# ifdef SAVE_THE_WORLD
#  undef SAVE_THE_WORLD
# endif

# define SAVE_THE_WORLD 42

typedef struct s_perso	t_perso;

struct					s_perso
{
	char	*name;
	double	life;
	int		age;
	int		profession;
};

#endif
