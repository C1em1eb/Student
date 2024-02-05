#include "libft.h"

/* int main(void)
{
const char haystack[] ="Hello Wor, this World Clement";
const char needle[] = "World";
size_t len = 25;
char *result;

result = ft_strnstr(haystack, needle, len);
if(result == haystack)
	printf("The needle is empty\n");
else if(result == NULL)
	printf("The needle '%s' was not found\n", needle);
else
	printf("The needle '%s' was found\n", needle);
return (0);
} */

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	ln;
	char	*ph;
	char	*pn;

	i = 0;
	j = 0;
	ph = (char *) haystack;
	pn = (char *) needle;
	if (pn[0] == '\0')
		return (ph);
	while (pn[j] != '\0')
	{
		j++;
		ln = j;
		j = 0;
	}
	while (ph[i] != '\0' && (i < len))
	{
		while (ph[i] == pn[j])
		{
			i++;
			j++;
			if (pn[j] == '\0')
				return (&ph[i - ln]);
		}
		if (ph[i] != pn[j])
		{
			j = 0;
			i++;
		}
	}
	return (NULL);
}
