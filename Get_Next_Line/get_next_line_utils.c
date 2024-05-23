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

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	int		i;
	int		j;
	int		len;
	char	*s3;

	i = 0;
	len = ft_strlen_cons(s1) + ft_strlen_cons(s2);
	s3 = malloc(sizeof(char) * (len + 1));
	if (s3 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
}

int	ft_strlen_cons(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
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
		if (p[i] == c)
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
