#ifndef LIBFTPRINT_H
# define LIBFTPRINT_H

#include "../Libft/libft.h"
#include <stdarg.h>

int	ft_putchar_len(char c, int len);
int	ft_putstr_len(char *s, int len);
int	ft_putnbr_len(int n, int len);
int	ft_putnbr_unsigned_len(int n, int len);
int	ft_print_hex_low(unsigned int i, int len);
int	ft_print_hex_up(unsigned int i, int len);
void	ft_rev_int_tab(unsigned char *tab, int size);
void	ft_putstr(unsigned char *str);
int	ft_printf(const char *format, ...);


#endif
