#compile
NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -pthread
SRC = sources/error_handle.c sources/main.c sources/utils.c sources/utils2.c sources/utils3.c sources/init.c sources/debug.c sources/sim.c sources/actions.c
#commands
RM = rm -rf
OBJ = $(SRC:.c=.o)
#includes
LIBFT = includes/42_libft/libft.a
PRINTF = includes/42_ftprintf/ft_printf/libftprintf.a

%.o : %.cJa agora

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
