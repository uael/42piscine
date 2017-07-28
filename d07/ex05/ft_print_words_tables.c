/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 23:24:17 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/08 23:24:19 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_words_tables(char **tab)
{
	char *sptr;

	while (*tab)
	{
		sptr = *tab;
		while (*sptr)
			ft_putchar(*sptr++);
		ft_putchar('\n');
		++tab;
	}
}
