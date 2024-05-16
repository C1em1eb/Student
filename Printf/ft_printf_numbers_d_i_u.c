#include "ft_printf.h"

int	ft_putnbr_len(int n, int len)
{
	char *tab;

	tab = ft_itoa(n);
	len = len + ft_strlen(tab);
	ft_putstr(tab);
	free (tab);
	return (len);
}

int	ft_putnbr_unsigned_len(unsigned int n, int len)
{
	char *tab;

	tab = ft_uitoa(n);
	len = len + ft_strlen(tab);
	ft_putstr(tab);
	free (tab);
	return (len);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

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

