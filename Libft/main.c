#include "libft.h"

// ft_atoi.c

int	main(void)
{
	char	str[] = "    	 ---++15465494648646666666666666666666666666654555qaad4525";
	int result;
	printf("la vieille chaine en char est %s\n", str);
	printf("=========================\n");
	result = ft_atoi(str);
	printf("la nouvelle chaine en int est %d\n", result);
	return (0);
}

/////////////////////////////////////////////////////////////////////

// ft_memchr.c

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

// ft_strchrc.c

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

//ft_strjoin.c

/* int main(void)
{
	char s1[] = "Clement";
	char s2[] = " Leblond";
	char	*result;

	result = ft_strjoin(s1, s2);
	printf("The concatenate string is : ""%s""\n", result);
	free (result);
	return (0);
	} */

/////////////////////////////////////////////////////////////////////

//ft_strlcat.c

/*int main(void)
{
const char source[] = "hello";
char destination[] = "hello";
size_t size = 2;
size_t result = 0;
//size_t oresult = 0;

result = ft_strlcat(destination, source, size);
//result = strlcat(destination, source, size);
printf("My the length of the concatenate string is %li\n", result);
//printf("OG length of the concatenate string is %li\n", oresult);
}
*/

/////////////////////////////////////////////////////////////////////

//ft_strncmp.c

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

//ft_strnstr.c

/* int main(void)
{
const char haystack[] ="Hello Wor, this World Clement";
const char needle[] = "World";
size_t len = 25;
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

//ft_strrchr.c

/*int main(void)
{
const char s[] = "Hello";
int c = 'l';
char *result;

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
} */

/////////////////////////////////////////////////////////////////////

// ft_strtrim.c

/* int main(void)
{
char s[] = "abbbbbbbbbbbaaaMy name is Clementabbbbbbbbbbbaaab";
char set[] = "ba";

char *result;
result = ft_strtrim(s, set);
printf("the trimed string is ""%s""\n", result);
free (result);
return (0);
}
 */

/////////////////////////////////////////////////////////////////////

//ft_substr.c

/* int main(void)
{
	char const s[] = "Bonjour, comment ça va?";
	unsigned int start = 21;
	size_t len = 3;
	char *result = NULL;

	result = ft_substr(s, start, len);
	printf("The substring is %s\n", result);
	free (result);
	return (0);
} */

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