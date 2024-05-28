/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:05:04 by cleblond          #+#    #+#             */
/*   Updated: 2024/05/28 14:44:22 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*p;
	int		len;

	i = 0;
	p = (char *)s;
	if (c == '\0')
	{
		len = ft_strlen(p);
		return (&p[len]);
	}
	while (p[i])
	{
		if (p[i] == (unsigned char)c)
			return (&p[i]);
		else if (p[i] != c)
			i++;
	}
	return (NULL);
}
