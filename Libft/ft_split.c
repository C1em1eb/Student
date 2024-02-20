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

static int ft_wordcounter(char const *s, char c);
static void ft_print_two_dimensions_array(char **s);
static void	ft_putstr(char *str);

int main(void)
{
	//char *test[] = {"Helloclement", "Worldzzzzzzzzzzzfzefzefzzzzza", "Salut", "Encore", "Bravoooooooooooooooo", NULL};
	char	s[] = "a?a";
	char	c = 'a';
	char	**result;

	result = ft_split(s, c);
	ft_putstr(s);
	ft_print_two_dimensions_array(result);
	free (result);
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
	int				wordcount;
	char			**split;
	int				i;
	unsigned int	start;
	int				row;
	size_t			len;

	if (s == NULL)
		return (NULL);
	wordcount = ft_wordcounter(s, c);
	split = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (split == NULL)
		return (NULL);
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
		else if (s[i] == c)
		{
			while (s[i] == c && s[i])
			i++;
		}
	}
	split[row] = NULL;
	return (split);
}

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
	write(1, "\n", 1);
}
