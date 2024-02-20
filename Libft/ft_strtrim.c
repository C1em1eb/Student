/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:05:48 by cleblond          #+#    #+#             */
/*   Updated: 2024/02/19 16:16:05 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strim;
	int		start;
	int		end;
	int		strimlen;

	strim = NULL;
	start = 0;
	end = ft_strlen((char *)s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strrchr(set, s1[end]) != NULL)
	{
		end--;
	}
	strimlen = end - start + 1;
	strim = (char *)malloc(sizeof(char) * (strimlen +1));
	if (strim == NULL)
		return (NULL);
	ft_strlcpy(strim, &s1[start], strimlen);
	strim[strimlen] = '\0';
	return (strim);
}
