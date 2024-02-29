/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:05:38 by cleblond          #+#    #+#             */
/*   Updated: 2024/02/28 15:23:41 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	ln;

	i = 0;
	j = 0;
	ln = ft_strlen(needle) - 1;
	if (needle == NULL || *needle == '\0' || len == 0)
		return ((char *)(haystack));
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i] == needle[j] && i < len)
		{
			i++;
			j++;
			if (needle[j] == '\0' && i - j < len)
				return ((char *)(&haystack[i - ln]));
		}
		i++;
	}
	return (NULL);
}
