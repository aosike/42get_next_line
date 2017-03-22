/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:00:03 by agundry           #+#    #+#             */
/*   Updated: 2017/03/21 17:48:38 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char keep[4864][BUFF_SIZE];
	t_gnl		gnl;

	gnl.f = 0;
	if (!gnlinit(&keep[fd], fd, &gnl, &line))
		return (-1);
	while (gnl.s > 0)
	{
		if ((gnl.b = ft_strchr(gnl.buf, '\n')))
			ft_strcpy(keep[fd], gnl.b + 1);
		else
			gnl.b = ft_strchr(gnl.buf, '\0');
		ft_bzero(gnl.b + 1, ((BUFF_SIZE + 1) - (gnl.b - gnl.buf)));
		gnl.f = linegetter(gnl.f, gnl.buf);
		gnl.s = *(gnl.b) == '\n' ? 0 : read(fd, gnl.buf, BUFF_SIZE);
	}
	*line = *(gnl.f) ? ft_strdup(gnl.f) : 0; ///////////////////fuck
	return (*line ? 1 : 0);
}

int	gnlinit(char (*keep)[BUFF_SIZE], int fd, t_gnl *gnl, char ***line)
{

	ft_bzero(gnl->buf, BUFF_SIZE + 1);
	gnl->s = BUFF_SIZE;
	if (fd < 0 || !line)
		return (0);
	if (*keep)
		ft_strcpy(gnl->buf, *keep);
	else
		gnl->s = read(fd, gnl->buf, BUFF_SIZE);
	if (gnl->s < 0)
		return (0);
	ft_bzero(*keep, BUFF_SIZE);
	return (1);
}

char	*linegetter(char *d, char *s)
{
	char	*tmp;
	char	*src;

	if (ft_strrchr(s, '\n'))
		src = ft_strndup(s, ft_strlen(s) - 1);
	else
		src = ft_strdup(s);
	if (d != NULL)
	{
		tmp = ft_strdup(d);
		ft_strdel(&d);
		d = ft_strjoin(tmp, src);
		ft_strdel(&tmp);
		ft_strdel(&src);
		return (d);
	}
	else
		d = ft_strdup(src);
	ft_strdel(&src);
	return (d);
}
