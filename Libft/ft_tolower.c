#include "libft.h"

/* int ft_tolower(int c);

int main(void)
{
	int result = 0;
	int c = 'J';
	result = ft_tolower(c);
	write(1, &result, 1);
	write(1, "\n", 1);
}
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c = c + 32);
	else
		return (c);
}
