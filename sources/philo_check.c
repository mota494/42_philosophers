/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:32:25 by mloureir          #+#    #+#             */
/*   Updated: 2024/09/11 14:30:57 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_all_ate(t_data *data)
{
	mutex_handle(&data->checker_mutex, M_LOCK);
	if (data->a_eat == data->n_philos)
	{
		mutex_handle(&data->checker_mutex, M_UNLOCK);
		return (0);
	}
	mutex_handle(&data->checker_mutex, M_UNLOCK);
	return (1);
}

int	check_if_dead(t_data *data)
{
	long	curt;
	int		i;

	i = 0;
	while (i < data->n_philos)
	{
		mutex_handle(&data->philo[i].philo_mutex, M_LOCK);
		curt = chrono() - data->philo[i].time_l_meal;
		if (curt > data->t_die + 1)
		{
			mutex_handle(&data->philo[i].philo_mutex, M_UNLOCK);
			write_status(P_DEAD, &data->philo[i]);
			data->dead = true;
			return (0);
		}
		mutex_handle(&data->philo[i].philo_mutex, M_UNLOCK);
		i++;
	}
	mutex_handle(&data->philo[i].philo_mutex, M_UNLOCK);
	return (1);
}

void	*philo_check(void *data)
{
	t_data	*observer;

	observer = (t_data *)data;
	while (1)
	{
		if (check_if_dead(observer) == 0)
			return (NULL);
		if (check_all_ate(observer) == 0)
			return (NULL);
	}
	return (NULL);
}
