/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:03:44 by cleblond          #+#    #+#             */
/*   Updated: 2024/02/19 20:17:37 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_nlength(int n)
{
	unsigned int	nlength;

	nlength = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		nlength = 1;
	while (n != 0)
	{
		n = n / 10;
		nlength++;
	}
	return (nlength);
}

static void	ft_fillchars(char *s, unsigned int number, unsigned int nlength)
{
	int	i;

	i = nlength - 1;
	while (number != 0)
	{
		s[i] = number % 10 + '0';
		number = number / 10;
		i--;
	}
	s[nlength] = '\0';
}

char	*ft_itoa(int n)
{
	char			*s;
	unsigned int	nlength;
	unsigned int	number;

	nlength = ft_nlength(n);
	number = n;
	s = (char *)malloc(sizeof(char) * (nlength + 1));
	if (s == NULL)
		return (NULL);
	if (n == 0)
	{
		s[0] = '0';
		s[1] = '\0';
	}
	if (n < 0)
	{
		s[0] = '-';
		number = -number;
	}
	ft_fillchars(s, number, nlength);
	return (s);
}
