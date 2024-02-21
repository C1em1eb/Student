/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:00:40 by cleblond          #+#    #+#             */
/*   Updated: 2024/02/21 15:00:41 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	number[11];
	int		i;

	i = 0;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	if (n == 0)
		write(fd, "0", 1);
	if (n < 0 && n != -2147483648)
	{
		n = -n;
		write(fd, "-", 1);
	}
	while (n > 0)
	{
		number[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		write(fd, &number[i], 1);
	}
}
