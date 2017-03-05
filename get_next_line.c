/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 11:49:11 by agundry           #+#    #+#             */
/*   Updated: 2017/03/04 19:37:52 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static char	*fdstr[256];
	char		buf[BUFF_SIZE + 1];
	char		*front;
	char		*back;
	size_t		rsize;

	ft_bzero(buf, (BUFF_SIZE + 1));
	if (fdstr[fd] && *fdstr[fd])  //ft_strdel of fdstr??
		ft_strcpy(buf, fdstr[fd]);
	rsize = 1;
	while ((!line[fd] || !(ft_strchr(line[fd], '\n'))) && rsize > 0) //appears as though line[fd] will always exist. 																			fucking lame
	{
		if ((back = ft_strchr(buf, '\n')))
			fdstr[fd] = !(*(back + 1)) ? NULL : ft_strdup((back + 1));
		else
			back = ft_strchr(buf, '\0');
		front = ft_strndup(buf, ((*back == '\n' ? (back + 1) : back) - buf)); //ft_strdel to front??
		line[fd] = linegetter(line[fd], front);
		ft_bzero(buf, BUFF_SIZE);
		if (!(ft_strchr(line[fd], '\n')))
			rsize = read(fd, buf, BUFF_SIZE);
	}
	return (*line[fd] ? 1 : 0);	
}

char	*linegetter(char *d, char *s)
{
	char	*tmp;

	if (d != NULL)
	{
		tmp = ft_strdup(d);
		if (*d)
			ft_strdel(&d);
		d = ft_strjoin(tmp, s);
		ft_strdel(&tmp);
		return (d);
	}
	else return (d = ft_strdup(s));
}
