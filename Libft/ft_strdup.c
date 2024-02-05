#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*dest;

	j = 0;
	if (src == NULL)
		return (0);
	while (src[j] != '\0')
	{
		j++;
	}
	dest = malloc((j + 1) * sizeof(char));
	if (dest == NULL)
	{
		exit (0);
	}
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
