/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:04:03 by cleblond          #+#    #+#             */
/*   Updated: 2024/02/19 16:04:04 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t	nmemb, size_t	size)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = NULL;
	i = 0;
	if (nmemb == 0 || size == 0)
		return (0);
	if (nmemb * size > 2147483648)
		return (0);
	else
	{
		tmp = malloc(nmemb * size);
		if (tmp == NULL)
			return (0);
	}
	while (i < (size * nmemb))
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}
