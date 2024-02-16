#include "libft.h"

char	*ft_strrchr(const char	*s, int c)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *) s;
	while (p[i] != '\0')
	{
		i++;
	}
	i = i - 1;
	while (i >= 0)
	{
		if (p[i] == c)
			return (&p[i]);
		else if (p[i] != c)
			i--;
	}
	return (0);
}
