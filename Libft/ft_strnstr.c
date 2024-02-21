/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:05:38 by cleblond          #+#    #+#             */
/*   Updated: 2024/02/19 16:05:40 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_cons(const char *s);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	ln;

	i = 0;
	j = 0;
	if (*needle == '\0' || *haystack == *needle)
		return ((char *)(haystack));
	ln = ft_strlen_cons(needle) - 1;
	while (haystack[i] && i < len)
	{
		while (haystack[i] == needle[j])
		{
			i++;
			j++;
			if (needle[j] == '\0')
				return ((char *)(&haystack[i - ln]));
		}
		j = 0;
		i++;
	}
	return (NULL);
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
