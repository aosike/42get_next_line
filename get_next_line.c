/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 13:55:33 by agundry           #+#    #+#             */
/*   Updated: 2017/02/21 17:21:14 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static char	*fdstr[256];
	char		*back;
	char		*front;
	char		*gotline;
	char		buf[BUFF_SIZE + 1];

	ft_bzero(buf, (BUFF_SIZE + 1));
	if (fdstr[fd])
		ft_strcpy(buf, fdstr[fd]);
	back = buf;
	gotline = NULL;
	while (!(*back == '\n') || !(*back == '\0' && back > &buf[BUFF_SIZE]))
	{
		reader(fd, buf);
		if ((back = ft_strchr(buf, '\n')) && *(back + 1))
			fdstr[fd] = ft_strdup((back + 1));
		else back = ft_strchr(buf, '\0');
		front = ft_strndup(buf, (back - buf + 1));
		gotline = linegetter(gotline, front);
	}
	line[fd] = *gotline ? ft_strdup(gotline) : NULL;
	return (*line[fd] ? 1 : 0);
}

void	reader(int fd, char *buf)
{
	static int	swich;

	if (!(*buf))
	{
		read(fd, buf, BUFF_SIZE);
		swich = 1;
	}
	else if (swich == 1)
	{
		ft_bzero(buf, (BUFF_SIZE + 1));
		read(fd, buf, BUFF_SIZE);
		swich = 1;
	}
}

char	*linegetter(char *d, char *s)
{
	char	*tmp;

	if (d != NULL)
	{
		tmp = ft_strdup(d);
		free(d);
		d = ft_strjoin(tmp, s);
		return (d);
	}
	else return (d = ft_strdup(s));
}
