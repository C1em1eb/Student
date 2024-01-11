#include <stddef.h>

void	*memset(void *s, int c, size_t n)
{
unsigned char	*p;
size_t	i;

p = s;
i = 0;
while(i < n)
{
	p[i] = (unsigned char)c;
	i++;
}
return (s);
}
