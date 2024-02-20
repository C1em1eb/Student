/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:05:00 by cleblond          #+#    #+#             */
/*   Updated: 2024/02/19 16:17:10 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* char	**ft_split(char const *s, char c);
static int ft_wordcounter(char const *s, char c); */

int main(void)
{
	//char 	s[] = "Hello World";
	char *test[] = {"Hello", "World", NULL};
	//char 	**result = NULL;
	int i = 0;
	//result = ft_split(s, ' ');

	while (i < ft_strlen(test))
	{
		int j = 0;
		while (j < NULL));
		{
			printf("%c", test[i][j]);
			j++;
		}
	printf("\n");
	i++;
	}
	return (0);
}
/*
static int ft_wordcounter(char const *s, char c)
{
	int i;
	int wordcounter;

	i = 0;
	wordcounter = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			wordcounter++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (wordcounter);
}

char	**ft_split(char const *s, char c)
{
	int		wordcount;
	char	**split;

	if (s == NULL)
		return (NULL);

	wordcount = ft_wordcounter(s, c);
	split = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (split == NULL)
		return (NULL);

	int j = 0;
	while (*s)
	{
		while (*s == c)
		s++;

		if (*s && *s != c)
		{
			const char *end = ft_strrchr(s, c);
			size_t len = (end != NULL) ? (size_t)(end - s + 1) : strlen(s);

			split[j] = ft_substr(s, 0, len);
			if (split[j] == NULL)
				return (NULL);
	s += len;
	j++;
	}
	}
	split[j] = NULL;
	return (split);
}
 */
