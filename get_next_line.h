/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 20:59:34 by agundry           #+#    #+#             */
/*   Updated: 2017/03/01 16:47:57 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include <fcntl.h>
# include "libft/libft.h"

/*typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	int				fd;
	struct s_list	*next;
}					t_list;
*/
int		get_next_line(const int fd, char **line);
char	*linegetter(char *d, char *s);
int		readwrap(int fd, char *buf, char *fdstr);

#endif
