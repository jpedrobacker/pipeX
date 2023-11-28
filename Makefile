SRCS =		pipex.c

OBJ =	$(SRCS:.c=.o)
CC =	cc
CFLAGS = -Wall -Werror -Wextra
NAME =	pipex.a

all: $(NAME)

$(NAME):
		ar -rcs $(NAME) $(OBJ)

.c.o:
		$(CC) -c $(CFLAGS) $<

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all
