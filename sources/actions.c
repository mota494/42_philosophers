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

int	eat(t_data *d)
{
	mutex_handle(&d->philo->lfork->fork, M_LOCK);
	write_status(P_FORK, d);
	mutex_handle(&d->philo->rfork->fork, M_LOCK);
	write_status(P_FORK, d);
	set_long(&d->philo->philo_mutex, &d->philo->time_l_meal, chrono());
	d->philo->count_meal++;
	write_status(P_EATING, d);
	ft_usleep(d->t_eat);
	if (d->n_must_eat == d->philo->count_meal)
		set_bool(&d->philo->philo_mutex, &d->philo->full, true);
	return (1);
}

void	write_status(int status, t_data *data)
{
	long	curr_time;

	curr_time = chrono() - data->sim_start;
	mutex_handle(&data->write_mutex, M_LOCK);
	if (data->sim_end == true || data->philo->full == true)
		return ;
	else
	{
		if (status == P_FORK)
			printf("%zu %d has taken a fork\n",
				curr_time, data->philo->p_id);
		else if (status == P_EATING)
			printf("%zu %d is eating\n",
				curr_time, data->philo->p_id);
		else if (status == P_SLEEP)
			printf("%zu %d is sleeping\n",
				curr_time, data->philo->p_id);
		else if (status == P_THINK)
			printf("%zu %d is thinking\n",
				curr_time, data->philo->p_id);
		else if (status == P_DEAD)
			printf("%zu %d has died\n",
				curr_time, data->philo->p_id);
	}
	mutex_handle(&data->write_mutex, M_UNLOCK);
}
