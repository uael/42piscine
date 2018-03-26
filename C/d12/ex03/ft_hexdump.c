/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 10:52:40 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/21 10:52:44 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

#define UNUSED(x) ((void)(x))
#define READ(v, f, b, l) (v = read(f, b, l))

#define EACCES_MSG ": Permission denied\n"
#define ENOENT_MSG ": No such file or directory\n"
#define EISDIR_MSG ": Is a directory\n"
#define EBADF_MSG ": Bad file descriptor\n"

int		ft_hexdump_errno(int err, char *file)
{
	if (err)
	{
		UNUSED(write(2, SNS("hexdump: ")));
		UNUSED(write(2, file, ft_strlen(file)));
	}
	if (err == EACCES)
		UNUSED(write(2, SNS(EACCES_MSG)));
	else if (err == ENOENT)
		UNUSED(write(2, SNS(ENOENT_MSG)));
	else if (err == EISDIR)
		UNUSED(write(2, SNS(EISDIR_MSG)));
	else if (err == EBADF)
		UNUSED(write(2, SNS(EBADF_MSG)));
	else
		return (0);
	return (errno);
}

int		ft_putnbr_base16(int nbr, int n)
{
	char	buffer[5000];
	int		i;
	int		neg;
	char	*base;

	base = "0123456789abcdef";
	i = 0;
	if (nbr < (neg = 0))
	{
		nbr = -nbr;
		neg = 1;
	}
	while (nbr >= 16)
	{
		buffer[++i] = base[nbr % 16];
		nbr /= 16;
	}
	buffer[++i] = base[nbr % 16];
	if (neg)
		buffer[++i] = '-';
	while ((n-- - i) > 0)
		write(1, "0", 1);
	while (i)
		write(1, buffer + i--, 1);
	return (0);
}

char	g_m = 0;
char	g_star = 0;

int		ft_hexdump_line(char *line, int len, unsigned c)
{
	int	i;

	if (g_m && ft_strall(line, g_m))
	{
		if (!g_star)
			write(g_star = 1, SNS("*\n"));
		return (0);
	}
	g_star = 0;
	ft_putnbr_base16(c * BUFFS, 8);
	write((i = -1) + 2, "  ", 2);
	while (++i < len)
		if (ft_putnbr_base16((int)line[i], 2)
			+ (i == 7 ? write(1, SNS("  ")) : write(1, SNS(" "))) == -1)
			return (errno);
	while (i++ < BUFFS)
		i == 8 ? write(1, SNS("    ")) : write(1, SNS("   "));
	write((i = -1) + 2, SNS(" |"));
	g_m = line[0];
	while (++i < len)
		if ((g_m == line[i] ? 1 : ((g_m = 0) + 1)) &&
			write(1, line[i] < 32 || line[i] > 126 ? "." : line + i, 1) == -1)
			return (-1);
	write(1, SNS("|\n"));
	return (errno);
}

int		ft_hexdump(int fd, char *buff, long *rs, unsigned *c)
{
	long p;

	if (fd == -1)
		return (fd);
	if (fd == 0)
	{
		while ((*rs +=
			read(fd, buff + *rs, (unsigned)(BUFFS - *rs))) != 0
			&& *rs != -1)
			if (*rs >= 16)
				if (ft_hexdump_line(buff, (int)*rs, (*c)++)
					== ((*rs = 0) - 1))
					break ;
	}
	else
	{
		while ((p = *rs) >= 0 && READ(*rs, fd, buff + p, (size_t)BUFFS - p) != 0
			&& (*rs + p) == 16)
			if (ft_hexdump_line(buff, (int)(*rs = 0) + BUFFS, (*c)++) == -1)
				break ;
		close(fd);
	}
	return (errno);
}

int		ft_dump_all(char *buff, char **files, int file_count)
{
	int			i;
	int			badf;
	unsigned	c;
	long		len;
	char		*file;

	i = -1;
	badf = 0;
	c = 0;
	len = 0;
	file = NULL;
	while (++i < file_count)
		if (ft_hexdump(open(file = files[i], O_RDONLY), buff, &len, &c) != 0)
			badf = ft_hexdump_errno(errno, file) != EISDIR || badf;
	if (len > 0)
		if (ft_hexdump_line(buff, (int)len, c) != 0)
			badf = ft_hexdump_errno(errno, file) != EISDIR || badf;
	if (errno == 0)
		write(ft_putnbr_base16((int)((c * BUFFS) + len), 8) + 1 & 1, SNS("\n"));
	return (badf && file ? ft_hexdump_errno(EBADF, file) : 0);
}
