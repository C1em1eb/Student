#include "libft.h"

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
