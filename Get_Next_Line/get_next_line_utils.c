#include "get_next_line.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	if (src == NULL)
		return (NULL);
	dest = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(const char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*p;
	int		len;

	i = 0;
	p = (char *)s;
	if (c == '\0')
	{
		len = ft_strlen(p);
		return (&p[len]);
	}
	while (p[i])
	{
		if (p[i] == (unsigned char)c)
			return (&p[i]);
		else if (p[i] != c)
			i++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;
	size_t	slen;

	slen = ft_strlen(s);
	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > slen)
		return (ft_strdup(""));
	if ((start + len) > slen)
		len = slen - start;
	substr = malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

// Dummy implementations of utility functions for demonstration purposes
/* char *ft_strdup(const char *s)
{
	char *dup = malloc(strlen(s) + 1);
	if (dup) strcpy(dup, s);
	return dup;
}

char *ft_strjoin(char const *s1, char const *s2)
{
	char *join = malloc(strlen(s1) + strlen(s2) + 1);
	if (join) {
		strcpy(join, s1);
		strcat(join, s2);
	}
	return join;
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *sub = malloc(len + 1);
	if (sub) {
		strncpy(sub, s + start, len);
		sub[len] = '\0';
	}
	return sub;
}

size_t ft_strlen(const char *s)
{
	return strlen(s);
}

char *ft_strchr(const char *s, int c)
{
	return strchr(s, c);
} */

