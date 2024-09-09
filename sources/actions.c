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

int	eatin(t_philos *d)
{
	set_long(&d->philo_mutex, &d->time_l_meal, chrono());
	mutex_handle(&d->data->data_mutex, M_LOCK);
	d->count_meal++;
	write_status(P_EATING, d);
	ft_usleep(d->data->t_eat);
	if (d->data->n_must_eat == d->count_meal)
	{
		set_bool(&d->philo_mutex, &d->full, true);
		d->data->a_eat += 1;
	}
	mutex_handle(&d->data->data_mutex, M_UNLOCK);
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
			printf("%s%zu%s %d has taken a fork\n", F, time, N,
				d->p_id);
		else if (status == P_EATING)
			printf("%s%zu%s %d is eating[%d]\n", F, time, N, d->p_id, d->count_meal);
		else if (status == P_SLEEP)
			printf("%s%zu%s %d is sleeping\n", F, time, N, d->p_id);
		else if (status == P_THINK)
			printf("%s%zu%s %d is thinking\n", F, time, N, d->p_id);
		else if (status == P_DEAD)
			printf("%s%zu%s %d has died\n", F, time, N, d->p_id);
	}
	mutex_handle(&d->data->write_mutex, M_UNLOCK);
}
