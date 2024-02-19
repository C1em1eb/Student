/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:05:34 by cleblond          #+#    #+#             */
/*   Updated: 2024/02/19 16:05:35 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		diff;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		diff = s1[i] - s2[i];
		if (diff == 0)
			i++;
		else if (diff > 0)
			return (diff);
		else
			return (diff);
	}
	return (0);
}
