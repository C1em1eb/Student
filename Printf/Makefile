SRCS = ft_printf.c ft_printf_words_c_s.c ft_printf_numbers_d_i_u.c ft_printf_hex_x_x.c ft_printf_pointers_p.c \
		ft_uitoa.c

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
