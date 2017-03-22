/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 20:59:34 by agundry           #+#    #+#             */
/*   Updated: 2017/03/21 17:33:57 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 42
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_gnl{
	char		buf[BUFF_SIZE + 1];
	int			s;
	char		*f;
	char		*b;
}				t_gnl;

int		get_next_line(const int fd, char **line);
int		gnlinit(char (*keep)[BUFF_SIZE], int fd, t_gnl *gnl, char ***line);
char	*linegetter(char *d, char *s);

#endif
