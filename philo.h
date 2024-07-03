#include <pthread.h>
#include <bits/pthreadtypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "includes/42_libft/libft.h"
#include "includes/42_ftprintf/ft_printf/ft_printf.h"

typedef struct s_philos
{
	pthread_t	*threads;
	int			n_philos;
	int			t_die;
	int			t_eat;
	int			t_sleep;
	int			n_must_eat;
}		t_philos;

/*main.c*/
int		main(int argc, char **argv);
void	pass_args(int ac, char **av, t_philos *philo);
/*error_handle.c*/
void	err_exit(void);
int		err_check(int ac, char **av);
/*utils.c*/
int		strdigit(char *str);
/*printable.c*/
void	printable(t_philos *philo);
