#include <string.h>

size_t strlcpy(char	*dst, const char	*src, size_t	dstsize)
{
size_t				l;
size_t				i;
unsigned char		*d;
const unsigned char	*s;

l = 0;
i = 0;
d = (unsigned char *)dst;
s = (const unsigned char *)src;
while(s[l] != '\0')
l++;
if(dstsize == 0)
{
return (l);
}
else
{
	while(i < dstsize && s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
d[i] = '\0';
return (l);
}
}
