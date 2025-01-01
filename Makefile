
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = pipex.c ft_substr.c ft_strncmp.c ft_strlen.c ft_strlcat.c ft_strdup.c ft_split.c \
	utils.c ft_strlcpy.c ft_strjoin.c ft_putchar.c ft_handle_percent.c ft_intlen.c ft_intlen_base.c \
    ft_puthexo.c ft_printf.c ft_putnbr.c ft_putnbr_unsigned.c ft_putptr.c ft_putstr.c
OBJS = $(SRCS:.c=.o)
NAME = pipex
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re