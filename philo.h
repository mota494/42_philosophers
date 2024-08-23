#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include "includes/42_libft/libft.h"
#include "includes/42_ftprintf/ft_printf/ft_printf.h"
typedef	struct s_fork
{
	int				f_id;
	pthread_mutex_t	fork;
}		t_fork;
typedef struct s_philos
{
	int			id;
	int			count_meal;
	int			full;
	int			time_l_meal;
	t_fork		*lfork;
	t_fork		*rfork;
	pthread_t	*thread;
}		t_philos;

typedef	struct s_data
{
	int			n_philos;
	int			t_die;
	int			t_eat;
	int			t_sleep;
	int			n_must_eat;
	int			sim_start;
	t_fork		*forks;
	t_philos	*philo;
}	t_data;

/*main.c*/
int		main(int argc, char **argv);
/*error_handle.c*/
void	err_exit(void);
int		err_check(int ac, char **av);
/*utils.c*/
int		strdigit(char *str);
