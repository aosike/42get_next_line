/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 20:59:34 by agundry           #+#    #+#             */
/*   Updated: 2017/03/11 14:34:08 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 420
# include <fcntl.h>
# include "libft/libft.h"

int		get_next_line(const int fd, char **line);
char	*linegetter(char *d, char *s, char *b);

#endif
