/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 04:25:14 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/09 04:25:17 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

int			ft_atoi(char *str);
int			ft_atoi_base(char *str, char *base);
int			ft_is_prime(int nb);
void		*ft_print_memory(void *addr, unsigned int size);
void		ft_putchar(char c);
void		ft_putnbr(int nb);
void		ft_putnbr_base(int nbr, char *base);
void		ft_putstr(char *str);
void		ft_putstr_non_printable(char *str);
int			ft_sqrt(int nb);
int			ft_str_is_alpha(char *str);
int			ft_str_is_lowercase(char *str);
int			ft_str_is_numeric(char *str);
int			ft_str_is_printable(char *str);
int			ft_str_is_uppercase(char *str);
char		*ft_strcapitalize(char *str);
char		*ft_strcat(char *dest, char *src);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strcpy(char *dest, char *src);
unsigned	ft_strlcat(char *dest, char *src, unsigned int size);
unsigned	ft_strlcpy(char *dest, char *src, unsigned int size);
int			ft_strlen(char *str);
char		*ft_strlowcase(char *str);
char		*ft_strncat(char *dest, char *src, int nb);
int			ft_strncmp(char *s1, char *s2, unsigned int n);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
char		*ft_strrev(char *str);
char		*ft_strstr(char *str, char *to_find);
char		*ft_strupcase(char *str);
void		ft_swap(int *a, int *b);

#endif
