/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:00:03 by agundry           #+#    #+#             */
/*   Updated: 2017/03/15 17:13:51 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	keep[256][BUFF_SIZE];
	char		buf[BUFF_SIZE + 1];
	char		*b;
	char		*f;
	size_t		s;

	ft_bzero(buf, BUFF_SIZE + 1); //VERY CLOSE - is adding newline to f.
	s = BUFF_SIZE;
	f = 0;
	if (*keep[fd])
		ft_strcpy(buf, keep[fd]);
	else
		s = read(fd, buf, BUFF_SIZE);
	ft_bzero(keep[fd], BUFF_SIZE);
	while (s > 0)
	{
		if ((b = ft_strchr(buf, '\n')))
			ft_strcpy(keep[fd], b + 1);
		else b = ft_strchr(buf, '\0');
		ft_bzero(b + 1, ((BUFF_SIZE + 1) - (b - buf)));
		f = linegetter(f, buf);
		s = (*b != '\n') ? read(fd, buf, BUFF_SIZE) : 0;
	}
	*line = f ? ft_strdup(f) : 0;
	return (*line ? 1 : 0);
}

char	*linegetter(char *d, char *s)
{
	char	*tmp;

	if (d != NULL)
	{
		tmp = ft_strdup(d);
		ft_strdel(&d);
		d = ft_strjoin(tmp, s);
		ft_strdel(&tmp);
		return (d);
	}
	else return (d = ft_strdup(s));
}
