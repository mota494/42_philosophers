/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:12:43 by mloureir          #+#    #+#             */
/*   Updated: 2024/09/08 15:32:47 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	write_status(int status, t_data *data)
{
	long curr_time;

	curr_time = chrono() - data->sim_start;
	mutex_handle(&data->write_mutex, M_LOCK);
	if (data->sim_end == true || data->philo->full == true)
		return ;
	else
	{
		if (status == P_FORK)
			printf("%zu %d has taken a fork\n", curr_time, data->philo->p_id);
		else if (status == P_EATING)
			printf("%zu %d is eating\n", curr_time, data->philo->p_id);
		else if (status == P_SLEEP)
			printf("%zu %d is sleeping\n", curr_time, data->philo->p_id);
		else if (status == P_THINK)
			printf("%zu %d is thinking\n", curr_time, data->philo->p_id);
		else if (status == P_DEAD)
			printf("%zu %d has died\n", curr_time, data->philo->p_id);
	}
	mutex_handle(&data->write_mutex, M_UNLOCK);
}