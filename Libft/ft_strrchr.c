/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:05:44 by cleblond          #+#    #+#             */
/*   Updated: 2024/02/28 15:14:57 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char	*s, int c)
{
	int		i;
	char	*p;
	int		len;

	i = 0;
	p = (char *) s;
	if (c == '\0')
	{
		len = ft_strlen(p);
		return (&p[len]);
	}
	while (p[i] != '\0')
	{
		i++;
	}
	i = i - 1;
	while (i >= 0)
	{
		if (p[i] == c)
			return (&p[i]);
		else if (p[i] != c)
			i--;
	}
	return (0);
}
