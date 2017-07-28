/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dope.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 09:07:25 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/13 09:07:27 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOPE_H
# define FT_DOPE_H

int				ft_atoi(char *str);
void			ft_putchar(char c);
void			ft_putnbr(int nb);
void			ft_putstr(char *str);
int				ft_strcmp(char *s1, char *s2);

typedef struct	s_opp
{
	char *op;
	char *(*dope)(int l, int r, int *out);
}				t_opp;

t_opp			*ft_opp(char *op);

char			*ft_add(int l, int r, int *out);
char			*ft_sub(int l, int r, int *out);
char			*ft_mul(int l, int r, int *out);
char			*ft_div(int l, int r, int *out);
char			*ft_mod(int l, int r, int *out);
char			*ft_usage(int l, int r, int *out);
char			*ft_dope(char *lop, char *op, char *rop, int *out);

#endif
