/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 20:27:38 by agundry           #+#    #+#             */
/*   Updated: 2017/02/16 17:14:34 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//change to BUFF_SIZE

int	get_next_line(const int fd, char **line)
{
	static char	*fdstr[256];
	char		*back;
	char		*front;
	char		*gotline;
	char		buf[BUFFSIZE + 1];
	
	back = NULL;
	ft_bzero(buf, (BUFFSIZE + 1));
	if (fdstr[fd])
		ft_strcpy(buf, fdstr[fd]);
	while (back == NULL || (*back != '\n' && *back != '\0'))
	{
		if (!(*buf))
			read(fd, buf, BUFFSIZE);
		if ((back = ft_strchr(buf, '\n')))
			fdstr[fd] = ft_strdup(buf);
		front = ft_strndup(buf, (back != NULL ? (back - buf) : BUFFSIZE));
		back = ft_strrchr(buf, '\0') ? : back;
		gotline = gotline == NULL ? ft_strdup(front) : ft_strjoin(gotline, front);
	}
	if (gotline)
		line[fd] = ft_strdup(gotline);
	return (*gotline ? 1 : 0);
}
