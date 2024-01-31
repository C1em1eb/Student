
#include <unistd.h>

int ft_toupper(int c);

/* int main(void)
{
	int result = 0;
	int c = 'J';
	result = ft_toupper(c);
	write(1, &result, 1);
	write(1, "\n", 1);
}
 */
int ft_toupper(int c)
{
if(c >= 'a' && c <= 'z')
	return (c = c - 32);
else
	return (c);
}
