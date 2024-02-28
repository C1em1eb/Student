/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:05:24 by cleblond          #+#    #+#             */
/*   Updated: 2024/02/28 14:58:14 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dst, const char	*src, size_t	dstsize)
{
	size_t				l;
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	l = 0;
	i = 0;
	d = (unsigned char *) dst;
	s = (const unsigned char *) src;
	while (s[l] != '\0')
		l++;
	if (dstsize == 0)
		return (l);
	while (i < (dstsize - 1) && s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (l);
}
