#include "libftprintf.h"

/* int main(void)
{
	unsigned int i;
	i = 465465495;
	int result;
	int result2;
	result = ft_print_hex_low(i);
	printf("\n");
	result2 = ft_print_hex_up(i);
	printf("\n%i\n", result);
	printf("%i\n", result2);
	return (0);
}
 */
int	ft_print_hex_low(unsigned int i, int len)
{
	unsigned int	remainder;
	int				j;
	unsigned char	hex[10] = {'\0'};

	j = 0;
	while (i > 0)
	{
		remainder = i % 16;
		i = i / 16;
		if (remainder > 9)
			hex[j] = remainder + 87;
		else
			hex[j] = remainder + '0';
		j++;
	}
	//hex[j++] = '0';
	//hex[j++] = 'x';
	ft_rev_int_tab (hex, j);
	ft_putstr(hex);
	return (len + j);
}

int	ft_print_hex_up(unsigned int i, int len)
{
	unsigned int	remainder;
	int				j;
	unsigned char	hex[10] = {'\0'};

	j = 0;
	while (i > 0)
	{
		remainder = i % 16;
		i = i / 16;
		if (remainder > 9)
			hex[j] = remainder + 55;
		else
			hex[j] = remainder + '0';
		j++;
	}
	//hex[j++] = '0';
	//hex[j++] = 'x';
	ft_rev_int_tab (hex, j);
	ft_putstr(hex);
	return (len + j);
}

void	ft_rev_int_tab(unsigned char *tab, int size)
{
	int				i;
	int				j;
	unsigned char	tmp;

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

void	ft_putstr(unsigned char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
