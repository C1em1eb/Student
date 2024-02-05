#include "libft.h"

/* int	main(void)
{
	const char	s[] = "Hello";
	int			c = 'H';
	char		*result;

	result = ft_memchr(s, c, 3);
	if (result != NULL)
	{
		printf("the adress of the pointer is %p\n", result);
		printf("the string of the pointer is %s\n", result);
		printf("the specific character of the pointer is %c\n", *result);
	}
	else
		printf("the character was not found\n");
	return (0);
}
 */
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
