#include "ft_printf.h"

int	ft_putnbr_len(int n, int len)
{
	char	number[11];
	int		i;

	i = 0;
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	if (n == 0)
		write(1, "0", 1);
	if (n < 0 && n != -2147483648)
	{
		n = -n;
		write(1, "-", 1);
	}
	while (n > 0)
	{
		number[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	len = len + i;
	while (i > 0)
	{
		i--;
		write(1, &number[i], 1);
	}
	return (len);
}

int	ft_putnbr_unsigned_len(int n, int len)
{
	char	number[11];
	int		i;

	i = 0;
	if (n == -2147483648)
		write(1, "2147483648", 10);
	if (n == 0)
		write(1, "0", 1);
	if (n < 0 && n != -2147483648)
	{
		n = -n;
	}
	while (n > 0)
	{
		number[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	len = len + i;
	while (i > 0)
	{
		i--;
		write(1, &number[i], 1);
	}
	return (len);
}
