/* #include "libft.h"

static int ft_wordcounter(char const *s, char c);

int main(void)
{
	char s[] = "Salut    t    je          m'apelle         Clement                 ";
	char c = ' ';
	int result;

	result = ft_wordcounter(s, c);
	printf("le nombre de mots dans la chaine est %d\n", result);
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
} */
