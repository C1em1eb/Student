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

static void ft_print_two_dimensions_array(char **s)
{
	int i;
	int j;
	int row;

	row = 0;
	i = 0;
	while (s[row] != NULL)
		row++;
	while (i < row)
	{
		j = 0;
		while (s[i][j] != '\0')
		{
			printf("%c", s[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

static void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\0", 1);
}

int main(void)
{
	char 	s[] = "Hello World";
	char *test[] = {"Helloclement", "Worldzzzzzzzzzzzfzefzefzzzzza", "Salut", "Encore", "Bravoooooooooooooooo", NULL};
	//char 	**result = NULL;
	//result = ft_split(s, ' ');

	ft_putstr(s);
	ft_print_two_dimensions_array(test);
	return (0);
}


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

