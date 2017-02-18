/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 13:55:33 by agundry           #+#    #+#             */
/*   Updated: 2017/02/14 17:00:31 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	t_list	*list;
	char	*back;
	char	*gotline;
	char	buf[BUFFSIZE + 1];
	char	front[BUFFSIZE + 1];
 
	if ((list = findinlist(fd)))  //store fd in content size? make new struct?
		buf = list->content;
	while (!back || (back[0] != '\n' && back[0] != '\0'))
	{
		if (!buf[0] || !back)
			read(fd, buf, BUFFSIZE);
		if ((back = ft_strchr(buf, '\n')))
		{
			ft_strdup(list->content, (back + 1));
			ft_strncpy(front, buf, (back - buf - 1));
		}
		else
			ft_strcpy(front, buf);
		back = ft_strchr(buf, '\0') ? ft_strchr(buf, '\0') : buf;
		if (!gotline)
			gotline = ft_strdup(front);
		else ft_strjoin(gotline, front);
	}
	if (gotline)
	{
		list->line = ft_strdup(gotline);
		return (1);
	}
	else return (0);
}
