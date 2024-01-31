#include <stdio.h>

/* int	ft_strncmp(const char *s1, const char *s2, size_t n);

int	main(void)
{
	int	result;

	result = ft_strncmp("abb", "abbewfwefwef", 0);
	if (result == 0)
	{
		printf("String 1 = String 2");
	}
	else if (result > 0)
		printf("String 1 > String 2");
	else
	{
		printf("String 1 < String 2");
	}
	return (0);
}
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int	diff;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
	diff = s1[i] - s2[i];
	if (diff == 0)
		i++;
	else if (diff > 0)
		return (diff);
	else
		return (diff);
	}
	return (0);
}
