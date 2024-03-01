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

	i = 0;
	j = 0;
	if (haystack == NULL || needle == NULL)
		return (NULL);
	if (*needle == '\0')
		return ((char *)(haystack));
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i] == needle[j] && i < len && needle[j] != '\0')
		{
			i++;
			j++;
			if (needle[j] == '\0')
				return ((char *)(&haystack[i - j]));
		}
		i = i - j + 1;
	}
	return (NULL);
}
