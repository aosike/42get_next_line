/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <agundry@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:47:00 by agundry           #+#    #+#             */
/*   Updated: 2017/04/04 13:58:19 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 42
# define MAX_FD 4864
# include <fcntl.h>
# include "libft/libft.h"

typedef	struct	s_gnl {
	char		s[BUFF_SIZE + 1];
	char		*b;
	char		*f;
	char		*tmp;
	char		*src;
	int			i;
}				t_gnl;

int				get_next_line(int fd, char **line);
#endif
