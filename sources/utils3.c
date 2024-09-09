/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:43:39 by mloureir          #+#    #+#             */
/*   Updated: 2024/09/08 15:44:50 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

size_t	ft_usleep(size_t time)
{
	size_t	start;

	start = chrono();
	while ((chrono() - start) < time)
		usleep(time * 1e3);
	return (0);
}

void	drop_fork(t_philos *data)
{
	if (data->p_id % 2 == 0)
	{
		mutex_handle(&data->rfork->fork, M_UNLOCK);
		mutex_handle(&data->lfork->fork, M_UNLOCK);
	}
	else
	{
		mutex_handle(&data->lfork->fork, M_UNLOCK);
		mutex_handle(&data->rfork->fork, M_UNLOCK);
	}
}

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
