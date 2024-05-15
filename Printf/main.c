#include "libftprintf.h"

int	main(void)
{
	int len;
	int len_og;
	int *p;
	int a;

	p = 0;
	a = 10;
	len = 0;
	len_og = 0;
	p = &a;
	printf("original:\n");
	//len_og = printf("%s DEF%d YGH%%IJK%uFLM%cNOP%sQRST", "clement", -10, 5, 'A', "test" );
	len_og = printf("ABC %%%s %p 10 %d %u %c %x %X%%aaaa", "clement", p, 400, 400, 'a', 495, 495);
	printf("\n%i char\n", len_og);
	printf("custom:\n");
	//len = ft_printf("%s DEF%d YGH%%IJK%uFLM%cNOP%sQRST", "clement", -10, 5, 'A', "test" );
	len = ft_printf("ABC %%%s %p 10 %d %u %c %x %X%%aaaa", "clement", p, 400, 400, 'a', 495, 495);
	ft_printf("\n%i char\n", len);
	return(0);
}
