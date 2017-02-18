/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 20:59:34 by agundry           #+#    #+#             */
/*   Updated: 2017/02/14 21:12:12 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFSIZE 32
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
int	get_next_line(const int fd, char **line);

#endif
