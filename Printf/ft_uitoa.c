#include "ft_printf.h"

static unsigned int	ft_nlength_un(unsigned int n)
{
	unsigned int	nlength;

	nlength = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		nlength++;
	}
	return (nlength);
}

static void	ft_fillchars_un(char *s, unsigned int number, unsigned int nlength)
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

char	*ft_uitoa(unsigned int n)
{
	char			*s;
	unsigned int	nlength;

	nlength = ft_nlength_un(n);
	s = (char *)malloc(sizeof(char) * (nlength + 1));
	if (s == NULL)
		return (NULL);
	if (n == 0)
	{
		s[0] = '0';
		s[1] = '\0';
	}
	ft_fillchars_un(s, n, nlength);
	return (s);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
