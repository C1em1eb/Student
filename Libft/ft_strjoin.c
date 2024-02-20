/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:05:14 by cleblond          #+#    #+#             */
/*   Updated: 2024/02/19 16:05:16 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	int		i;
	int		j;
	int		len;
	char	*s3;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc(sizeof(char) * (len + 1));
	if (s3 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i++];
	}
	j = 0;
	while (s2[j] != '\0')
	{
		s3[i + j] = s2[j++];
	}
	s3[i + j] = '\0';
	return (s3);
}
