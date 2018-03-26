/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 20:22:32 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/20 20:22:33 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>

# define BUFFS (2048)
# define SNS(s) (s),(sizeof(s)-1)
# define UNUSED(x) ((void)(x))
# define HAS_ERR(e) (e==EACCES||e==ENOENT||e==EISDIR||e==EBADF)

typedef unsigned char	t_bool;

typedef struct			s_opts
{
	t_bool	plus;
	int		n;
	int		file_count;
	char	**files;
}						t_opts;

unsigned				ft_strlen(const char *str);
char					*ft_strncpy(char *dest, char *src, unsigned int n);
int						ft_tail(t_opts *opts);
int						ft_tail_opts(t_opts *self, int ac, char **av);
int						ft_tail_fatal(const char *err, const char *d, int r);
int						ft_tail_errno(char *file);

#endif
