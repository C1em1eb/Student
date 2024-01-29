#include <string.h>
#include <stdio.h>

size_t ft_strlcat(char	*dst, const char	*src, size_t	dstsize);

int main(void)
{
const char source[] = "hello";
char destination[] = "helloo";
size_t size = 1;
size_t result = 0;
//size_t oresult = 0;

result = ft_strlcat(destination, source, size);
//result = strlcat(destination, source, size);
printf("My the length of the concatenate string is %li\n", result);
//printf("OG length of the concatenate string is %li\n", oresult);
}

size_t ft_strlcat(char	*dst, const char	*src, size_t	dstsize)
{
size_t				ls;
size_t				ld;
size_t				i;
unsigned char		*d;
const unsigned char	*s;

ls = 0;
ld = 0;
i = 0;
d = (unsigned char *)dst;
s = (const unsigned char *)src;
while(s[ls] != '\0')
ls++;
while(d[ld] != '\0')
ld++;
if(ld == dstsize)
{
return (ls + ld + 1);
}
else if(dstsize >= (ls + ld))
{
	while(i < (dstsize + ls) && s[i] != '\0')
	{
		d[ld] = s[i];
		i++;
	}
d[ld + i] = '\0';
return (ls + ld);
}
else
{
	return (ls + ld);
}
}
