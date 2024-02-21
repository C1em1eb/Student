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

static int	ft_strlen_cons(const char *s);

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	int		i;
	int		j;
	int		len;
	char	*s3;

	i = 0;
	len = ft_strlen_cons(s1) + ft_strlen_cons(s2);
	s3 = malloc(sizeof(char) * (len + 1));
	if (s3 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
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
