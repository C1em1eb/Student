#include <string.h>
#include <stdio.h>
/*
size_t ft_strlcat(char	*dst, const char	*src, size_t	dstsize);

int main(void)
{
const char source[] = "hello";
char destination[] = "hello";
size_t size = 2;
size_t result = 0;
//size_t oresult = 0;

result = ft_strlcat(destination, source, size);
//result = strlcat(destination, source, size);
printf("My the length of the concatenate string is %li\n", result);
//printf("OG length of the concatenate string is %li\n", oresult);
}
*/
size_t	ft_strlcat(char	*dst, const char	*src, size_t	dstsize)
{
	size_t				ls;
	size_t				ld;
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	ls = 0;
	ld = 0;
	i = 0;
	d = (unsigned char *) dst;
	s = (const unsigned char *) src;
	while (s[ls] != '\0')
		ls++;
	while (d[ld] != '\0')
		ld++;
	if (ld >= dstsize)
		return (ls + ld);
	else if (dstsize >= (ls + ld))
	{
		while (i < (dstsize - ld - 1) && s[i] != '\0')
		{
			d[ld] = s[i];
			ld++;
			i++;
		}
		d[ld] = '\0';
		return (ls + ld);
	}
	else
		return (ls + dstsize);
}
