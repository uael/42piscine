/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:30:47 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/20 16:30:49 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define SNS(s) (s),(sizeof(s)-1)
#define UNUSED(x) ((void)(x))
#define BUFFS (4096)

int		ft_display_fatal(const char *err, unsigned len, int fd, int rcode)
{
	UNUSED(write(fd, err, len));
	return (rcode);
}

int		main(int ac, char **av)
{
	char	buff[BUFFS];
	int		fd;
	long	rsize;

	if (ac < 2)
		return (ft_display_fatal(SNS("File name missing.\n"), 2, 1));
	if (ac > 2)
		return (ft_display_fatal(SNS("Too many arguments.\n"), 2, 1));
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (1);
	while ((rsize = read(fd, buff, BUFFS)) != 0 && rsize != -1)
		write(1, buff, (unsigned)rsize);
	close(fd);
	return (rsize == 0);
}
