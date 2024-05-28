#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "/Libft/libft.h"
# include <stdarg.h>

int		ft_putchar_len(char c, int len);
int		ft_putstr_len(char *s, int len);
int		ft_putpointer_len(unsigned long long p, int len);
int		ft_putnbr_len(int n, int len);
int		ft_putnbr_unsigned_len(unsigned int n, int len);
int		ft_print_hex_low(unsigned int i, int len);
int		ft_print_hex_up(unsigned int i, int len);
void	ft_rev_char_tab(char *tab, int size);
void	ft_putstr(char *str);
void	ft_rev_unchar_tab(unsigned char *tab, int size);
void	ft_putstr_unchar(unsigned char *str);
int		ft_printf(const char *format, ...);
char	*ft_uitoa(unsigned int n);
int		ft_write_nill(int len);
void	ft_case_selector(const char *format, va_list args, int *len, int *i);

#endif
