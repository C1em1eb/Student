SRCS = ft_printf.c ft_printf_words.c ft_printf_numbers.c ft_print_hex.c ft_print_pointer.c
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
