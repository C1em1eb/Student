/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:05:19 by cleblond          #+#    #+#             */
/*   Updated: 2024/02/28 14:48:07 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char	*src, size_t	size)
{
	size_t	i;
	size_t	ls;
	size_t	ld;

	ls = ft_strlen(src);
	ld = ft_strlen(dst);
	i = 0;
	if (size <= ld)
		return (size + ls);
	while (((ld + i + 1) < size) && src[i] != '\0')
	{
		dst[ld + i] = src[i];
		i++;
	}
	if (ld < size)
		dst[ld + i] = '\0';
	return (ld + ls);
}
