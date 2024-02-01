#include <string.h>
#include <stdio.h>

char *ft_strnstr(const char *haystack, const char *needle, size_t len);

int main(void)
{
const char haystack[] ="Hello World, this is Clement";
const char needle[] = "World";
size_t len = 5;
char *result;

result = ft_strnstr(haystack, needle, len);
if(result == haystack)
	printf("The needle is empty\n");
else if(result == NULL)
	printf("The needle '%s' was not found\n", needle);
else
	printf("The needle '%s' was found\n", needle);
return (0);
}

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
size_t i;
size_t j;
i = 0;
j = 0;
char *ph;
char *pn;
ph = (char*)haystack;
pn = (char *)needle;
 if(pn[0] == '\0')
 return (ph);
 while(ph[i] != '\0' && (i < len))
 {
	while(ph[i] == pn[j])
	{
		i++;
		j++;
		if(pn[j] != '\0')
		{
			return (&pn[i]);
		}
	}
	if(ph[i] != pn[j])
	{
		j = 0;
		i++;
	}
 }
 return (NULL);
}
