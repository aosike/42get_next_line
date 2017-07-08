/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <agundry@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:47:00 by agundry           #+#    #+#             */
/*   Updated: 2017/04/04 13:58:19 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	gnl_lineget(t_gnl *gnl, char (*keep)[BUFF_SIZE], int fd)
{
	if ((gnl->b = ft_strchr(gnl->s, '\n')))
		ft_strcpy(*keep, gnl->b + 1);
	else
		gnl->b = ft_strchr(gnl->s, '\0');
	gnl->src = ft_strndup(gnl->s, gnl->b - gnl->s);
	if (gnl->f && *gnl->f)
		gnl->tmp = ft_strdup(gnl->f);
	else
		gnl->tmp = ft_strnew(0);
	ft_strdel(&gnl->f);
	gnl->f = ft_strjoin(gnl->tmp, gnl->src);
	ft_strdel(&gnl->tmp);
	ft_strdel(&gnl->src);
	if (*gnl->b != '\n')
	{
		ft_bzero(gnl->s, BUFF_SIZE + 1);
		if ((gnl->i = read(fd, gnl->s, BUFF_SIZE)) < 0)
			return (-1);
	}
	else
		gnl->i = 0;
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	keep[MAX_FD][BUFF_SIZE];
	t_gnl		gnl;

	if (fd < 0 || fd > MAX_FD || !line)
		return (-1);
	ft_bzero(gnl.s, BUFF_SIZE + 1);
	gnl.i = BUFF_SIZE;
	if (*keep[fd])
		ft_strcpy(gnl.s, keep[fd]);
	else if ((gnl.i = read(fd, gnl.s, BUFF_SIZE)) < 0)
		return (-1);
	ft_bzero(keep[fd], BUFF_SIZE);
	gnl.f = 0;
	*line = 0;
	while (gnl.i > 0)
		if (gnl_lineget(&gnl, &(keep[fd]), fd) == -1)
		{
			ft_strdel(&gnl.f);
			return (-1);
		}
	if (gnl.f)
		*line = ft_strdup(gnl.f);
	ft_strdel(&gnl.f);
	return (*line ? 1 : 0);
}
