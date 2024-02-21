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

static int	ft_wordcounter(char const *s, char c);
static char	**ft_exctract(char const *s, char **split, char c, int wordcount);

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
	split = ft_exctract(s, split, c, wordcount);
	return (split);
}

static int	ft_wordcounter(char const *s, char c)
{
	int	i;
	int	wordcounter;

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

static char	**ft_exctract(char const *s, char **split, char c, int wordcount)
{
	int				i;
	unsigned int	start;
	int				row;
	size_t			len;

	i = 0;
	row = 0;
	while (s[i] != '\0' && row < wordcount)
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			len = i - start;
			split[row] = ft_substr(s, start, len);
			row++;
		}
		while (s[i] == c && s[i])
			i++;
	}
	split[row] = NULL;
	return (split);
}
