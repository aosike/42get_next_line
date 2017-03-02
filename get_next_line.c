/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 13:55:33 by agundry           #+#    #+#             */
/*   Updated: 2017/03/01 17:21:52 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//should front (thus, line) include the trailing newline?

int	get_next_line(const int fd, char **line)
{
	static char	*fdstr[256];
	char		*back;
	char		*front;
	char		buf[BUFF_SIZE + 1];

	ft_bzero(buf, (BUFF_SIZE + 1));
	line[fd] = NULL;
	if (fdstr[fd] && *fdstr[fd])
		ft_strcpy(buf, fdstr[fd]);
	back = buf;
	front = NULL;
	while ((*back != '\n') && !(*back == '\0' && back > &buf[BUFF_SIZE]))
	{
		if (readwrap(fd, buf, fdstr[fd]))
			ft_strdel(&fdstr[fd]);
		if ((back = ft_strchr(buf, '\n')))
			fdstr[fd] = !(*(back + 1)) ? NULL : ft_strdup((back + 1));
		else
			back = ft_strchr(buf, '\0');
		front = ft_strndup(buf, (back - buf));
		line[fd] = linegetter(line[fd], front);
		ft_strdel(&front);
	}
	return (line[fd] ? 1 : 0);
}

int	readwrap(int fd, char *buf, char *fdstr)
{
	if (!(*buf))
	{
		read(fd, buf, BUFF_SIZE);
		return (0);
	}
	else if (fdstr && *fdstr)
		return (1);
	else
	{
		ft_bzero(buf, (BUFF_SIZE + 1));
		read(fd, buf, BUFF_SIZE);
	}
	return (0);
}

char	*linegetter(char *d, char *s)
{
	char	*tmp;

	if (d != NULL)
	{
		tmp = ft_strdup(d);
		ft_strdel(&d);
		d = ft_strjoin(tmp, s);
		return (d);
	}
	else return (d = ft_strdup(s));
}
