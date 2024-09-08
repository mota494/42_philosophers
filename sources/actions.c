/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:12:43 by mloureir          #+#    #+#             */
/*   Updated: 2024/09/08 15:24:59 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	write_status(int status, t_data *data)
{
	long curr_time;

	curr_time = chrono() - data->sim_start;
	mutex_handle(&data->write_mutex, M_LOCK);
	if (status == 1)
		printf("%zu %d has taken a fork", curr_time, data->philo->p_id);
	mutex_handle(&data->write_mutex, M_UNLOCK);
}