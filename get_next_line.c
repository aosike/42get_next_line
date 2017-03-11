/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 11:49:11 by agundry           #+#    #+#             */
/*   Updated: 2017/03/11 15:11:57 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static char	*fdstr[256];
	char		buf[BUFF_SIZE + 1]; ///might have to malloc in order to save lines :///
	char		*front;
	char		*back;
	size_t		rsize;

	ft_bzero(buf, (BUFF_SIZE + 1));
	if (fdstr[fd] && *fdstr[fd])
	{
		ft_strcpy(buf, fdstr[fd]);
		ft_strdel(&fdstr[fd]);
	}
	rsize = BUFF_SIZE;
	while (rsize > 0)
	{
		if ((back = ft_strchr(buf, '\n')))
			fdstr[fd] = !(*(back + 1)) ? NULL : ft_strdup((back + 1));
		else
			back = ft_strchr(buf, '\0');
		front = linegetter(front, buf, back);
		if (*back != '\n')
		{
			ft_bzero(buf, (BUFF_SIZE + 1));      //would save lines here : see top
			rsize = read(fd, buf, BUFF_SIZE);
		}
		else rsize = 0;
	}
	*line = *front ? ft_strndup(front, (ft_strlen(front) - 1)) : NULL;
	ft_strdel(&front);
	return (*line ? 1 : 0);	
}

char	*linegetter(char *d, char *s, char *b)
{
	char	*tmp;
	char	*tmp1;

	tmp1 = ft_strndup(s, (((*b == '\n') ? (b + 1) : b) - s));
	if (d != NULL)
	{
		tmp = ft_strdup(d);
		if (*d)
			ft_strdel(&d);
		d = ft_strjoin(tmp, tmp1);
		if (*tmp)
			ft_strdel(&tmp);
		if (*tmp1)
			ft_strdel(&tmp1);
		return (d);
	}
	else
	{
		d = ft_strdup(tmp1);
		if (*tmp1)
			ft_strdel(&tmp1);
		return (d);
	}
}
