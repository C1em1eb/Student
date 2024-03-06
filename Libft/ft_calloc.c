/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:04:03 by cleblond          #+#    #+#             */
/*   Updated: 2024/03/06 15:34:59 by cleblond         ###   ########.fr       */
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
		return (malloc(0));
	if (nmemb * size / size != nmemb)
		return (NULL);
	else
	{
		tmp = malloc(nmemb * size);
		if (tmp == NULL)
			return (NULL);
	}
	while (i < (size * nmemb))
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}
