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
	int i;
	int j;
	int len;
	char *s3;

	s3 = NULL;
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
	{
		j++;
	}
	len = i + j;
	s3 = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (s3 == NULL)
		return (0);
	while(i < len - j)
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while(i < len)
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}



