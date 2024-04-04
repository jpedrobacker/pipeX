NAME = pipex
LIBFTPRINTF = libftprintf/libftprintf.a
LIBFT = libftprintf/libft/libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC_DIR = src/
FIND = $(shell find $(SRC_DIR))
SRC = $(filter %.c, $(FIND))

all: $(NAME)

$(NAME): $(SRC)
		$(CC) $(SRC) $(LIBFTPRINTF) -o $(NAME)

checkpoint:
	@git add -A
	@git commit -m "checkpoint at $$(date '+%Y-%m-%dT%H:%M:%S%z')"
	@git push
	@echo Checkpoint created and pushed to remote

lib:
	@make -C libftprintf

clean:
		@make clean -C libftprintf
		rm -rf $(NAME)

fclean: clean
		@make fclean -C libftprintf

re: fclean lib all
