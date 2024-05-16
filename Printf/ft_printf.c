#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			ft_case_selector(format, args, &len, &i);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			len++;
			i++;
		}
	}
	va_end(args);
	return (len);
}

void	ft_case_selector(const char *format, va_list args, int *len, int *i)
{
	if (format[*i] == 'c')
		*len = ft_putchar_len(va_arg(args, int), *len);
	else if (format[*i] == 's')
		*len = ft_putstr_len(va_arg(args, char *), *len);
	else if (format[*i] == 'p')
		*len = ft_putpointer_len(va_arg(args, unsigned long long), *len);
	else if (format[*i] == 'd' || format[*i] == 'i')
		*len = ft_putnbr_len(va_arg(args, int), *len);
	else if (format[*i] == 'u')
		*len = ft_putnbr_unsigned_len(va_arg(args, unsigned int), *len);
	else if (format[*i] == 'x')
		*len = ft_print_hex_low(va_arg(args, unsigned int), *len);
	else if (format[*i] == 'X')
		*len = ft_print_hex_up(va_arg(args, unsigned int), *len);
	else if (format[*i] == '%' )
	{
		write(1, "%%", 1);
		(*len)++;
	}
}
