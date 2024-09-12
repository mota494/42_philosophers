/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:12:43 by mloureir          #+#    #+#             */
/*   Updated: 2024/09/11 14:29:32 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	eatin(t_philos *d)
{
	mutex_handle(&d->data->data_mutex, M_LOCK);
	if (d->data->a_eat == d->data->n_philos || d->data->dead == true)
	{
		drop_fork(d);
		mutex_handle(&d->data->data_mutex, M_UNLOCK);
		return (0);
	}
	mutex_handle(&d->data->data_mutex, M_UNLOCK);
	mutex_handle(&d->philo_mutex, M_LOCK);
	d->time_l_meal = chrono();
	d->count_meal++;
	write_status(P_EATING, d);
	mutex_handle(&d->data->data_mutex, M_LOCK);
	if (d->data->n_must_eat == d->count_meal)
		d->data->a_eat += 1;
	mutex_handle(&d->data->data_mutex, M_UNLOCK);
	mutex_handle(&d->philo_mutex, M_UNLOCK);
	ft_usleep(d->data->t_eat);
	drop_fork(d);
	return (1);
}

int	sleepin(t_philos *d)
{
	mutex_handle(&d->data->data_mutex, M_LOCK);
	if (d->data->a_eat == d->data->n_philos || d->data->dead == true)
	{
		mutex_handle(&d->data->data_mutex, M_UNLOCK);
		return (0);
	}
	mutex_handle(&d->data->data_mutex, M_UNLOCK);
	write_status(P_SLEEP, d);
	ft_usleep(d->data->t_sleep);
	return (1);
}

int	think(t_philos *d)
{
	mutex_handle(&d->data->data_mutex, M_LOCK);
	if (d->data->a_eat == d->data->n_philos || d->data->dead == true)
	{
		mutex_handle(&d->data->data_mutex, M_UNLOCK);
		return (0);
	}
	mutex_handle(&d->data->data_mutex, M_UNLOCK);
	write_status(P_THINK, d);
	return (1);
}

void	write_status(int status, t_philos *d)
{
	long	time;

	mutex_handle(&d->data->data_mutex, M_LOCK);
	if (d->data->dead == true || d->data->a_eat == d->data->n_philos)
	{
		mutex_handle(&d->data->data_mutex, M_UNLOCK);
		return ;
	}
	mutex_handle(&d->data->data_mutex, M_UNLOCK);
	time = chrono() - d->data->sim_start;
	mutex_handle(&d->data->write_mutex, M_LOCK);
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
	mutex_handle(&d->data->write_mutex, M_UNLOCK);
}
