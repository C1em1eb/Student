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

int	ft_putnbr_unsigned_len(int n, int len)
{
	char	number[11];
	int		i;

	i = 0;
	n = (unsigned int)n;
	if (n == -2147483648)
		write(1, "2147483648", 10);
	if (n == 0)
		write(1, "0", 1);
	if (n < 0 && n != -2147483648)
		n = -n;
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

void	ft_rev_char_tab(char *tab, int size)
{
	int				i;
	int				j;
	char	tmp;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		tmp = tab[j];
		tab[j] = tab[i];
		tab[i] = tmp;
		i++;
		j--;
	}
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
