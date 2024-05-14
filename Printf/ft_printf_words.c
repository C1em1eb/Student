#include "libftprintf.h"

int	ft_putchar_len(char c, int len)
{
	write(1, &c, 1);
	return (len + 1);
}

int	ft_putstr_len(char *s, int len)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (len + i);
}
