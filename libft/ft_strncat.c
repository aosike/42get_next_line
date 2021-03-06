/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:43:29 by agundry           #+#    #+#             */
/*   Updated: 2016/12/14 17:43:36 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*d;

	d = s1;
	while (*s1)
		s1++;
	while (*s2 && n-- > 0)
		*s1++ = *s2++;
	*s1 = '\0';
	return (d);
}
