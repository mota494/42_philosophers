#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include "includes/42_libft/libft.h"
#include "includes/42_ftprintf/ft_printf/ft_printf.h"
#define M_INIT 1
#define	M_DESTROY 2
#define	M_LOCK 3
#define	M_UNLOCK 4
typedef	struct s_fork
{
	int				f_id;
	pthread_mutex_t	fork;
}		t_fork;
typedef struct s_philos
{
	int			p_id;
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
	int			sim_end;
	t_fork		*forks;
	t_philos	*philo;
}	t_data;

/*main.c*/
int		main(int argc, char **argv);
/*error_handle.c*/
void	err_exit(void);
int		err_check(int ac, char **av);
void	err_code(int i);
/*utils.c*/
int		strdigit(char *str);
void	*ret_malloc(size_t bytes);
void	mutex_handle(pthread_mutex_t *mtx, int opt);
/*init.c*/
void	init(t_data *data);
/*debug.c*/
void    print_all(t_data *data, t_fork *forks, t_philos *philo);