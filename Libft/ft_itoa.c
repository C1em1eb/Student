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

static int	ft_nlength(int n);
static void	ft_fillchars(char *s, int n, int nlength, int sign);

/* char		*ft_itoa(int n);

int	main(void)
{
	int		n;
	char	*result;

	n = 1;
	result = ft_itoa(n);
	printf("%s\n", result);
	free (result);
	return (0);
} */

static int	ft_nlength(int n)
{
	int	nlength;
	int	sign;

	if (!n)
		return (0);
	if (n >= 0)
		sign = 0;
	else
		sign = 1;
	nlength = 0;
	while (n != 0)
	{
		n = n / 10;
		nlength++;
	}
	return (nlength + sign);
}

static void	ft_fillchars(char *s, int n, int nlength, int sign)
{
	int	i;

	i = nlength - 1;
	while (i >= 0 + sign)
	{
		s[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	s[nlength] = '\0';
}

char	*ft_itoa(int n)
{
	char	*s;
	int		nlength;
	int		sign;

	sign = 0;
	nlength = ft_nlength(n);
	s = (char *)malloc(sizeof(char) * (nlength + 1));
	if (s == NULL)
		return (NULL);
	if (n == 0)
	{
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	if (n < 0)
	{
		sign = 1;
		s[0] = '-';
		n = -n;
	}
	ft_fillchars(s, n, nlength, sign);
	return (s);
}
