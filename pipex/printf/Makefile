NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADERS = ft_printf.h

SRCS = ft_putchar.c ft_putstr.c ft_putnbr.c ft_handle_percent.c \
       ft_intlen.c ft_puthexo.c ft_putptr.c \
       ft_printf.c ft_putnbr_unsigned.c ft_intlen_base.c \
       

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re