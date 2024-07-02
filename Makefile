#compile
NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = sources/error_handle.c sources/main.c sources/utils.c sources/printable.c
#commands
RM = rm -rf
OBJ = $(SRC:.c=.o)
#includes
LIBFT = includes/42_libft/libft.a
PRINTF = includes/42_ftprintf/ft_printf/libftprintf.a

%.o : %.c
	$(CC) $(CFLAGS) -c $*.c -o $*.o

all: $(NAME)

$(LIBFT):
	@make --silent -C includes/42_libft

$(PRINTF):
	@make --silent -C includes/42_ftprintf/ft_printf

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF)

clean:
	$(RM) $(OBJ)
	@make --silent -C includes/42_ftprintf/ft_printf clean
	@make --silent -C includes/42_libft clean

fclean: clean
	$(RM) $(NAME)
	@make --silent -C includes/42_ftprintf/ft_printf fclean
	@make --silent -C includes/42_libft fclean

re: fclean all
