/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:59:28 by mloureir          #+#    #+#             */
/*   Updated: 2024/09/08 15:44:34 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdbool.h>
#include "includes/42_libft/libft.h"
#include "includes/42_ftprintf/ft_printf/ft_printf.h"
#define M_INIT 1
#define M_DESTROY 2
#define M_LOCK 3
#define M_UNLOCK 4
#define P_FORK 1
#define P_EATING 2
#define P_SLEEP 3
#define P_THINK 4
#define P_DEAD 5

typedef struct s_fork
{
	int				f_id;
	pthread_mutex_t	fork;
}		t_fork;

typedef struct s_philos
{
	int			p_id;
	int			count_meal;
	bool		full;
	long		time_l_meal;
	t_fork		*lfork;
	t_fork		*rfork;
	pthread_mutex_t	philo_mutex;
	pthread_t	thread;
}		t_philos;

typedef struct s_data
{
	long			n_philos;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	long			n_must_eat;
	long			sim_start;
	bool			sim_end;
	bool			sync;
	pthread_mutex_t	data_mutex;
	pthread_mutex_t	write_mutex;
	t_fork			*forks;
	t_philos		*philo;
}	t_data;

/*main.c*/
int		main(int argc, char **argv);
/*error_handle.c*/
void	err_exit(void);
void	free_exit(t_data *data);
int		err_check(int ac, char **av);
void	err_code(int i);
/*utils.c*/
int		strdigit(char *str);
void	*ret_calloc(size_t nmemb, size_t size);
void	mutex_handle(pthread_mutex_t *mtx, int opt);
void	sync_threads(t_data *data);
bool	sim_finish(t_data *data);
/*init.c*/
void	init(t_data *data);
/*debug.c*/
void	print_all(t_data *d, t_fork *f, t_philos *p);
/*sim.c*/
void	sim_start(t_data *data);
/*utils2.c*/
void	set_bool(pthread_mutex_t *mutex, bool *dest, bool value);
bool	get_bool(pthread_mutex_t *mutex, bool *value);
void	set_long(pthread_mutex_t *mutex, long *dest, long value);
bool	get_long(pthread_mutex_t *mutex, long *value);
long	chrono(void);
/*actions.c*/
int		eatin(t_data *d);
int		sleepin(t_data *d);
int		think(t_data *d);
void	write_status(int status, t_data *data);
/*utils3.c*/
size_t	ft_usleep(size_t time);
