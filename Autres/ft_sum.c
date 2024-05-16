/* #include "libftprintf.h"
#include "libftprintf.h"

int ft_sum(int count, ...);

int main(int argc, char *argv[])
{
	int	result;
	int	i;
	int num;

	result = 0;
	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		result = ft_sum(1, num) + result;
		i++;
	}
	printf("The result is %d\n", result);
	return result;
}

int ft_sum(int count, ...)
{
	va_list args;
	int sum;

	va_start(args, count);
	sum = 0;
	while (count > 0)
	{
	sum = sum + va_arg(args, int);
	count--;
	}
	va_end(args);
	return sum;
}
 */
