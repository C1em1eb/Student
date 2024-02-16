#include "libft.h"

char *ft_strtrim(char const *s1, char const *set);

int main(void)
{
char s[] = "abbbbbbbbbbbaaaMy name is Clementabbbbbbbbbbbaaab";
char set[] = "ba";

char *result;
result = ft_strtrim(s, set);
printf("the trimed string is ""%s""\n", result);
free (result);
return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
	char	*strim;
	int		start;
	int		end;
	int		strimlen;

	strim = NULL;
	start = 0;
	end = ft_strlen((char *)s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strrchr(set, s1[end]) != NULL)
	{
		end--;
	}
	strimlen = end - start + 1;
	strim = (char *)malloc(sizeof(char) * (strimlen +1));
	if (strim == NULL)
		return (NULL);
	ft_strlcpy(strim, &s1[start], strimlen);
	return (strim);
}




