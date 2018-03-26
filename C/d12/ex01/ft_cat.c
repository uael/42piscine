/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 17:10:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/20 17:10:33 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define SNS(s) (s),(sizeof(s)-1)
#define UNUSED(x) ((void)(x))
#define BUFFS (28000)
#define EACCES_MSG ": Permission denied\n"
#define ENOENT_MSG ": No such file or directory\n"
#define EISDIR_MSG ": Is a directory\n"
#define EBADF_MSG ": Bad file number\n"
#define EAGAIN_MSG ": Resource temporarily unavailable\n"
#define EINTR_MSG ": Interrupted function call\n"
#define EIO_MSG ": Input/output error\n"
#define EINVAL_MSG ": Invalid argument\n"

unsigned	ft_strlen(char *str)
{
	char	*end;

	end = str;
	while (*end)
		++end;
	return ((unsigned)(end - str));
}

void		ft_err(char *file)
{
	UNUSED(write(2, SNS("cat: ")));
	UNUSED(write(2, file, ft_strlen(file)));
	if (errno == EACCES)
		UNUSED(write(2, SNS(EACCES_MSG)));
	else if (errno == ENOENT)
		UNUSED(write(2, SNS(ENOENT_MSG)));
	else if (errno == EISDIR)
		UNUSED(write(2, SNS(EISDIR_MSG)));
	else if (errno == EBADF)
		UNUSED(write(2, SNS(EBADF_MSG)));
	else if (errno == EAGAIN)
		UNUSED(write(2, SNS(EAGAIN_MSG)));
	else if (errno == EINTR)
		UNUSED(write(2, SNS(EINTR_MSG)));
	else if (errno == EIO)
		UNUSED(write(2, SNS(EIO_MSG)));
	else if (errno == EINVAL)
		UNUSED(write(2, SNS(EINVAL_MSG)));
	else
		UNUSED(write(2, SNS(": Unknown error\n")));
}

int			ft_cat(int fd)
{
	char	buff[BUFFS];
	long	rsize;

	if (fd == -1)
		return (fd);
	while ((rsize = read(fd, buff, BUFFS)) != 0 && rsize != -1)
		if (write(1, buff, (unsigned)rsize) == -1)
			return (1);
	if (rsize == -1)
		return (1);
	if (fd != 0)
		close(fd);
	return (0);
}

int			main(int ac, char **av)
{
	long	i;

	if (ac < 2)
		return (ft_cat(0));
	i = 0;
	while (++i < ac)
		if (ft_cat(open(av[i], O_RDONLY)) != 0)
			ft_err(av[i]);
	return (0);
}
