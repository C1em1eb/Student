#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*string;
	size_t	i;
	int		len;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = (int) ft_strlen((char *)s);
	string = malloc(sizeof(char) * (len + 1));
	if (string == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		string[i] = f(i, (char)s[i]);
		i++;
	}
	string[i] = '\0';
	return (string);
}
