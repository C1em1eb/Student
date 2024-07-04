SRCS =  ft_printf.c \
		sources/ft_printf_words_c_s.c \
		sources/ft_printf_numbers_d_i.c \
		sources/ft_printf_hex_x_x.c \
		sources/ft_printf_pointers_p.c \
		sources/ft_printf_numbers_u.c

OBJS := $(SRCS:%.c=%.o)

NAME = libftprintf.a

CC = cc

CCFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
