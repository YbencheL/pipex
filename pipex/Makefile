
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = pipex.c ft_substr.c ft_strncmp.c ft_strlen.c ft_strlcat.c ft_strdup.c ft_split.c \
	utils.c ft_strlcpy.c
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