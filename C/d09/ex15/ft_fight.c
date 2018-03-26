/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 14:10:58 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/14 14:11:00 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_fight.h"

void	ft_putsr6(char *str)
{
	char *sptr;

	sptr = str;
	while (*sptr)
		++sptr;
	write(1, str, sptr - str);
}

void	ft_fight(t_perso *a, t_perso *d, int power, char *desc)
{
	if (d->life <= 0 || a->life <= 0)
		return ;
	ft_putsr6(a->name);
	ft_putsr6(" does a ");
	ft_putsr6(desc);
	ft_putsr6(" on ");
	ft_putsr6(d->name);
	write(1, "\n", 1);
	d->life -= power;
	if (d->life < 0)
	{
		ft_putsr6(d->name);
		ft_putsr6(" is dead");
		write(1, "\n", 1);
		d->life = 0;
	}
}
