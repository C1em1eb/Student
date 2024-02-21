/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:05:19 by cleblond          #+#    #+#             */
/*   Updated: 2024/02/19 16:05:20 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_cons(const char *s);

size_t	ft_strlcat(char	*dst, const char	*src, size_t	dstsize)
{
	size_t	i;
	size_t	ld;
	size_t	ls;

	ld = ft_strlen_cons(dst);
	ls = ft_strlen_cons(src);
	i = 0;
	if (ld >= dstsize)
		return (ls + dstsize);
	else if (dstsize >= ls + ld)
	{
		while (i < (dstsize - ld - 1) && src[i] != '\0')
		{
			dst[ld + i] = src[i];
			i++;
		}
		dst[ld + i] = '\0';
		return (ls + ld);
	}
	else
		return (ls + dstsize);
}

static int	ft_strlen_cons(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
