/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 18:35:55 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/20 18:35:58 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "ft_tail.h"

int		ft_tail_opts(t_opts *self, int ac, char **av)
{
	char	*c_arg;
	int		n;
	int		i;

	if (ac < 2)
		return (ft_tail_fatal("option requires an argument", "c", 1));
	i = 1;
	c_arg = av[i];
	if (*c_arg == '-' && *(c_arg + 1) == 'c')
		c_arg += 2;
	if (*c_arg == '\0' && (ac < 3 || !*(c_arg = av[++i])))
		return (ft_tail_fatal("option requires an argument", "c", 1));
	n = 0;
	if ((self->plus = (t_bool)(c_arg[n] == '+')) || c_arg[n] == '-')
		++n;
	self->n = 0;
	while (c_arg[n] >= '0' && c_arg[n] <= '9')
		self->n = self->n * 10 + c_arg[n++] - '0';
	if ((unsigned)n != ft_strlen(c_arg))
		return (ft_tail_fatal("illegal offset", c_arg, 1));
	self->file_count = i < ac ? ac - i - 1 : 0;
	self->files = i < ac ? av + i + 1 : NULL;
	return (0);
}

void	ft_tail_begin(int fd, int n)
{
	long	size;
	char	buff[BUFFS];

	while ((size = read(fd, buff, BUFFS)) != 0)
		if (write(1, buff + n, (unsigned)(size - n)) == -1)
			break ;
		else
			n = 0;
}

void	ft_tail_end(int fd, int n)
{
	char	*buff[2];
	long	sizes[2];
	int		i;
	int		j;

	if ((buff[0] = malloc(sizeof(char) * n)) == NULL ||
		(buff[1] = malloc(sizeof(char) * n)) == NULL)
		return ;
	sizes[0] = 0;
	sizes[1] = 0;
	i = 0;
	while ((sizes[i] = read(fd, buff[i], (size_t)n)) == n)
		i ^= 1;
	if (sizes[j = i ^ 1] && sizes[i] < n)
		write(1, buff[j] + sizes[j] - (n - sizes[i]), (size_t)n - sizes[i]);
	write(1, buff[i], (size_t)sizes[i]);
	if (fd != 0)
		close(fd);
	free(buff[0]);
	free(buff[1]);
}

int		ft_tail(t_opts *opts)
{
	int		i;
	int		fd;

	i = -1;
	while (++i < opts->file_count)
	{
		if ((fd = open(opts->files[i], O_RDONLY)) == -1)
			return (ft_tail_errno(opts->files[i]));
		if (opts->file_count > 1)
		{
			if (i > 0)
				write(1, SNS("\n"));
			write(1, SNS("==> "));
			write(1, opts->files[i], ft_strlen(opts->files[i]));
			write(1, SNS(" <==\n"));
		}
		if (opts->plus)
			ft_tail_begin(fd, opts->n - 1);
		else
			ft_tail_end(fd, opts->n);
	}
	return (ft_tail_errno(opts->files[i]));
}
