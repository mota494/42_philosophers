/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:59:28 by mloureir          #+#    #+#             */
/*   Updated: 2024/09/09 12:30:14 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"

typedef pthread_mutex_t	t_mutex;

typedef struct s_fork
{
	int				f_id;
	pthread_mutex_t	fork;
}		t_fork;

typedef struct s_data
{
	long			n_philos;
	long			t_die;
	long			t_eat;
	int				a_eat;
	long			t_sleep;
	long			n_must_eat;
	long			sim_start;
	bool			sim_end;
	bool			sync;
	t_mutex			data_mutex;
	t_mutex			write_mutex;
	t_fork			*forks;
	struct s_philos	*philo;
}	t_data;

typedef struct s_philos
{
	int			p_id;
	int			count_meal;
	bool		full;
	long		time_l_meal;
	t_fork		*lfork;
	t_fork		*rfork;
	t_mutex		philo_mutex;
	pthread_t	thread;
	t_data		*data;
}		t_philos;

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
void	sync_threads(t_philos *data);
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
int		grab_fork(t_philos *d);
int		eatin(t_philos *d);
int		sleepin(t_philos *d);
int		think(t_philos *d);
void	write_status(int status, t_philos *data);
/*utils3.c*/
size_t	ft_usleep(size_t time);
void	drop_fork(t_philos *data);
