SRCS =		pipex.c

OBJ =	$(SRCS:.c=.o)
CC =	gcc
CFLAGS = -Wall -Werror -Wextra
NAME =	pipex.a
LIBFTPRINTFDIR = ft_printf
PRINTFNAME = libftprintf.a

makelib:
	make -C $(LIBFTPRINTFDIR)
	cp $(LIBFTPRINTFDIR)/$(PRINTFNAME) .
	mv $(PRINTFNAME) $(NAME)

run: makelib
	$(CC) mainpipex.c $(NAME) -o pipex

all: $(NAME)

$(NAME):
		ar -rcs $(NAME) $(OBJ)

.c.o:
		$(CC) -c $(CFLAGS) $<

clean:
		rm -rf $(OBJ)
		cd $(LIBFTPRINTFDIR) && make clean

fclean: clean
		rm -rf $(NAME)
		cd $(LIBFTPRINTFDIR) && make fclean

re: fclean all
