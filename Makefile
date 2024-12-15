CC = cc 
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_putaddress.c ft_puthexa.c ft_nbrlen.c \
	ft_strlen.c ft_putchar_fd.c ft_putstr_fd.c  ft_putnbr_fd.c ft_putunsigned.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re