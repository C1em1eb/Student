/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:06:22 by cleblond          #+#    #+#             */
/*   Updated: 2024/02/28 14:14:34 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_atoi(const char *str)

/* int	main(void)
{
	char	str[] = "+-54";
	int result;
	printf("la vieille chaine en char est %s\n", str);
	printf("=========================\n");
	printf("la fonction originale renvoie %d\n", atoi(str));
	result = ft_atoi(str);
	printf("la nouvelle chaine en int est %d\n", result);
	return (0);
} */

/////////////////////////////////////////////////////////////////////

// char		*ft_itoa(int n);

/* int	main(void)
{
	int		n;
	char	*result;

	n = -2147483648;
	result = ft_itoa(n);
	printf("%s\n", result);
	free (result);
	return (0);
}
 */
/////////////////////////////////////////////////////////////////////

// void	*ft_memchr(const void	*s, int c, size_t	n)

/* int	main(void)
{
	const char	s[] = "Hello";
	int			c = 'H';
	char		*result;

	result = ft_memchr(s, c, 3);
	if (result != NULL)
	{
		printf("the adress of the pointer is %p\n", result);
		printf("the string of the pointer is %s\n", result);
		printf("the specific character of the pointer is %c\n", *result);
	}
	else
		printf("the character was not found\n");
	return (0);
}
 */

/////////////////////////////////////////////////////////////////////

// char	*ft_strchr(const char *s, int c)

/*int main(void)
{
const char s[] = "Hello";
int c = 'l';
char *result;

result = ft_strchr(s, c);
if (result != NULL)
{
	printf("the adress of the pointer is %p\n", result);
	printf("the string of the pointer is %s\n", result);
	printf("the specific character of the pointer is %c\n", *result);
}
else
{
    printf("Character not found\n");
}
return (0);
} */

/////////////////////////////////////////////////////////////////////

// char	*ft_strjoin(char const	*s1, char const	*s2)

/* int main(void)
{
	char s1[] = "lorem ipsum";
	char s2[] = " dolor sit amet";
	char	*result;

	result = ft_strjoin(s1, s2);
	printf("The concatenate string is :%s\n", result);
	free (result);
	return (0);
	}
 */
/////////////////////////////////////////////////////////////////////

// size_t	ft_strlcat(char	*dst, const char	*src, size_t	size)
/* #include "libft.h"

int main(void)
{
const char source[] = " world";
char destination[] = "hello";
size_t size = 0;
size_t result = 0;
size_t oresult = 0;

result = ft_strlcat(destination, source, size);
oresult = strlcat(destination, source, size);
printf("The length of the concatenate string is %li\n", result);
printf("OG length of the concatenate string is %li\n", oresult);
} */

/////////////////////////////////////////////////////////////////////

// char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))

/*static char ft_upper(unsigned int i, char c);

int	main(void)
{
char s[] = "hello";
char *result;

printf("the old string is %s\n", s);
result = ft_strmapi(s, ft_upper);
printf("the new string is %s\n", result);
return (0);
}

static char ft_upper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return c - 'a' + 'A';
	else
	return c;
} */

/////////////////////////////////////////////////////////////////////

// int	ft_strncmp(const char *s1, const char *s2, size_t n)

/*int	main(void)
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

/////////////////////////////////////////////////////////////////////

// char	*ft_strnstr(const char *haystack, const char *needle, size_t len)

/* int main(void)
{
const char haystack[] ="lorem ipsipsum dolor sit amet";
const char needle[] = "ipsum";
size_t len = 30;
char *result;

result = ft_strnstr(haystack, needle, len);
if(result == haystack)
	printf("The needle is empty\n");
else if(result == NULL)
	printf("The needle '%s' was not found\n", needle);
else
	printf("The needle '%s' was found\n", needle);
return (0);
} */

/////////////////////////////////////////////////////////////////////

// char	**ft_split(char const *s, char c)

/* static void	ft_print_two_dimensions_array(char **s);
static void	ft_putstr(char *str);

int	main(void)
{
	char	s[] = " aSalut Je M'appelle Clément  et   toi?";
	char	c = ' ';
	char	**result;

	result = ft_split(s, c);
	ft_putstr(s);
	ft_print_two_dimensions_array(result);
	free (result);
	return (0);
}

static void	ft_print_two_dimensions_array(char **s)
{
	int	i;
	int	j;
	int	row;

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
 */
/////////////////////////////////////////////////////////////////////

// char	*ft_strrchr(const char	*s, int c)

/* int	main(void)
{
	const char	s[] = "Hellco";
	int			c = 'c';
	char		*result;

	result = ft_strrchr(s, c);
	if (result != NULL)
	{
		printf("the adress of the pointer is %p\n", result);
		printf("the string of the pointer is %s\n", result);
		printf("the specific character of the pointer is %c\n", *result);
	}
	else
	{
		printf("Character not found\n");
	}
	return (0);
}
 */
/////////////////////////////////////////////////////////////////////

// char *ft_strtrim(char const *s1, char const *set)

/* int main(void)
{
char s[] = "abbbbbbbbbbbaaaMy name is Clementabbbbbbbbbbbaaab";
char set[] = "bafwef";

char *result;
result = ft_strtrim(s, set);
printf("the trimed string is ""%s""\n", result);
free (result);
return (0);
}

 */
/////////////////////////////////////////////////////////////////////

// char	*ft_substr(char const	*s, unsigned int	start, size_t	len)

/* int main(void)
{
	char const s[] = "lorem ipsum dolor sit amet";
	unsigned int start = 400;
	size_t len = 20;
	char *result = NULL;

	result = ft_substr(s, start, len);
	printf("The substring is %s\n", result);
	free (result);
	return (0);
}
 */
/////////////////////////////////////////////////////////////////////

// int ft_tolower(int c);

/*int main(void)
{
	int result = 0;
	int c = 'J';
	result = ft_tolower(c);
	write(1, &result, 1);
	write(1, "\n", 1);
}
 */

/////////////////////////////////////////////////////////////////////

//int	ft_toupper(int c);

/*int	main(void)
{
	int result = 0;
	int c = 'J';
	result = ft_toupper(c);
	write(1, &result, 1);
	write(1, "\n", 1);
}
 */

/////////////////////////////////////////////////////////////////////

/* static int ft_wordcounter(char const *s, char c);

int main(void)
{
	char s[] = "Salut    t    je    m'apelle       Clement       ";
	char c = ' ';
	int result;

	result = ft_wordcounter(s, c);
	printf("le nombre de mots dans la chaine est %d\n", result);
	return (0);
} */

/////////////////////////////////////////////////////////////////////
