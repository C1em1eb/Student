 #include <string.h>

void	*memcpy(void *dest, const void *src, size_t n)
{
unsigned char	*p;
size_t	i;

p = dest;
i = 0;
while(i < n)
{
	p[i] = src[i];
	i++;
}
	return (dest);
}
