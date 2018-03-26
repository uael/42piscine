/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 00:07:36 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/24 00:07:38 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

#define EACCES_MSG ": Permission denied\n"
#define ENOENT_MSG ": No such file or directory\n"
#define EISDIR_MSG ": Is a directory\n"
#define EBADF_MSG ": Bad file number\n"

int		ft_tail_fatal(const char *err, const char *d, int r)
{
	UNUSED(write(2, SNS("tail: ")));
	UNUSED(write(2, err, ft_strlen(err)));
	UNUSED(write(2, SNS(" -- ")));
	UNUSED(write(2, d, ft_strlen(d)));
	UNUSED(write(2, SNS("\n")));
	return (r);
}

int		ft_tail_errno(char *file)
{
	if (HAS_ERR(errno))
	{
		UNUSED(write(2, SNS("tail: ")));
		UNUSED(write(2, file, ft_strlen(file)));
	}
	if (errno == EACCES)
		UNUSED(write(2, SNS(EACCES_MSG)));
	else if (errno == ENOENT)
		UNUSED(write(2, SNS(ENOENT_MSG)));
	else if (errno == EISDIR)
		UNUSED(write(2, SNS(EISDIR_MSG)));
	else if (errno == EBADF)
		UNUSED(write(2, SNS(EBADF_MSG)));
	else
		return (0);
	return (1);
}
