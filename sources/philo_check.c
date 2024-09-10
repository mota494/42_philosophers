/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:32:25 by mloureir          #+#    #+#             */
/*   Updated: 2024/09/10 13:32:26 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_all_ate(t_data *data)
{
	mutex_handle(&data->data_mutex, M_LOCK);
	if (data->a_eat == data->n_philos)
	{
		set_bool(&data->data_mutex, &data->sim_end, true);
		mutex_handle(&data->checker_mutex, M_UNLOCK);
		return (0);
	}
	mutex_handle(&data->data_mutex, M_UNLOCK);
	return (1);
}

void	*philo_check(void *data)
{
	t_data	*observer;

	observer = (t_data *)data;
	while (1)
	{
		if (check_all_ate(observer) == 0)
			return (NULL);
	}
	return (NULL);
}
