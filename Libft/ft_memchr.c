#include "libft.h"

void	*ft_memchr(const void	*s, int c, size_t	n)
{
	unsigned char	*p;
	unsigned char	d;
	size_t			i;

	p = (unsigned char *)s;
	d = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (p[i] == d)
			return (&p[i]);
		i++;
	}
	return (0);
}
