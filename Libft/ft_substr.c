#include "libft.h"

char	*ft_substr(char const	*s, unsigned int	start, size_t	len)
{
	unsigned int i;
	char	*substr;

	i = 0;
	substr = NULL;
	while (s[i] != '\0')
	{
		i++;
	}
	substr = malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (0);
	if (start > i || (start + len) > i)
		return (NULL);
	i = 0;
	while ( i < len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
