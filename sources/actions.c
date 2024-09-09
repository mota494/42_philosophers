/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:12:43 by mloureir          #+#    #+#             */
/*   Updated: 2024/09/08 15:46:30 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	grab_fork(t_philos *d)
{
	if (d->p_id % 2 == 0)
	{
		mutex_handle(&d->rfork->fork, M_LOCK);
		write_status(P_FORK, d);
		mutex_handle(&d->lfork->fork, M_LOCK);
		write_status(P_FORK, d);
	}
	else
	{
		mutex_handle(&d->lfork->fork, M_LOCK);
		write_status(P_FORK, d);
		mutex_handle(&d->rfork->fork, M_LOCK);
		write_status(P_FORK, d);
	}
	return (1);
}

int	eatin(t_philos *d)
{
	set_long(&d->philo_mutex, &d->time_l_meal, chrono());
	d->count_meal++;
	write_status(P_EATING, d);
	ft_usleep(d->data->t_eat);
	if (d->data->n_must_eat == d->count_meal)
		set_bool(&d->philo_mutex, &d->full, true);
	drop_fork(d);
	return (1);
}

void	write_status(int status, t_philos *d)
{
	long	time;

	time = chrono() - d->data->sim_start;
	mutex_handle(&d->data->write_mutex, M_LOCK);
	if (d->data->sim_end == true || d->full == true)
		return ;
	else
	{
		if (status == P_FORK)
			printf("%s%zu%s %d has taken a fork\n", F, time, N, d->p_id);
		else if (status == P_EATING)
			printf("%s%zu%s %d is eating\n", F, time, N, d->p_id);
		else if (status == P_SLEEP)
			printf("%s%zu%s %d is sleeping\n", F, time, N, d->p_id);
		else if (status == P_THINK)
			printf("%s%zu%s %d is thinking\n", F, time, N, d->p_id);
		else if (status == P_DEAD)
			printf("%s%zu%s %d has died\n", F, time, N, d->p_id);
	}
	mutex_handle(&d->data->write_mutex, M_UNLOCK);
}
