#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int len;
	int len_og;
	/* int *p;
	int a; */

	/* p = 0;
	a = 10; */
	len = 0;
	len_og = 0;
	/* p = &a; */
	printf("original:\n");
	//len_og = printf("%s DEF%d YGH%%IJK%uFLM%cNOP%sQRST", "clement", -10, 5, 'A', "test" );
	len_og = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("\n%i char\n", len_og);
	printf("custom:\n");
	//len = ft_printf("%s DEF%d YGH%%IJK%uFLM%cNOP%sQRST", "clement", -10, 5, 'A', "test" );
	len = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	ft_printf("\n%i char\n", len);
	return(0);
}
