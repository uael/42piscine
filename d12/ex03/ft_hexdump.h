/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 10:52:50 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/21 10:52:52 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

# define BUFFS (16)
# define SNS(s) (s),(sizeof(s)-1)

unsigned	ft_strlen(const char *str);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
int			ft_strall(char *str, char c);
int			ft_dump_all(char *buff, char **files, int file_count);
int			ft_hexdump(int fd, char *buff, long *rs, unsigned *c);
int			ft_hexdump_line(char *line, int len, unsigned c);
int			ft_hexdump_errno(int err, char *file);
int			ft_putnbr_base16(int nbr, int n);

#endif
