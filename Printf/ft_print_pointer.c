#include "ft_printf.h"

int	ft_putpointer_len(unsigned long long p, int len)
{
	unsigned int	remainder;
	int				j;
	unsigned char	hex[19] = {'\0'};

	j = 0;
	if (p == 0)
	{
		write(1, "(nil)", 5);
		return (len + 5);
	}
	while (p > 0)
	{
		remainder = p % 16;
		p = p / 16;
		if (remainder > 9)
			hex[j] = remainder + 87;
		else
			hex[j] = remainder + '0';
		j++;
	}
	hex[j++] = 'x';
	hex[j++] = '0';
	ft_rev_unchar_tab (hex, j);
	ft_putstr_unchar(hex);
	return (len + j);
}
