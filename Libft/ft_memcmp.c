#include "libft.h"

int	ft_memcmp(const void	*s1, const void	*s2, size_t	n)
{
	size_t			i;
	int				diff;
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		diff = ps1[i] - ps2[i];
		if (diff == 0)
			i++;
		else if (diff > 0)
			return (1);
		else
			return (-1);
	}
	return (0);
}
