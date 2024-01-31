//The strrchr() function returns a pointer to the last occurrence of the character c in the string s.

/* #include <stdio.h>

char *ft_strrchr(const char *s, int c);

int main(void)
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

char *ft_strrchr(const char *s, int c)
{
int i;
i = 0;
char *p;
p = (char*)s;
while(p[i] != '\0')
{
	i++;
}
i = i - 1;
while(i >= 0)
{
	if(p[i] == c)
	return (&p[i]);
	else if(p[i] != c)
	i--;
}
 return (0);
}

