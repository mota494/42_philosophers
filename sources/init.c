/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:52:06 by miguel            #+#    #+#             */
/*   Updated: 2024/09/08 15:19:47 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void    give_fork(t_philos *philo, t_fork *fork, int pos, long n_philo)
{
    philo[pos].lfork = &fork[pos];
    if (pos == n_philo - 1)
        philo[pos].rfork = &fork[0];
    else
        philo[pos].rfork = &fork[pos + 1];
}

void    mutex_init(t_data *data)
{
    int i;

    i = 0;
    while (i < data->n_philos)
    {
        mutex_handle(&data->forks[i].fork, M_INIT);
        data->forks[i].f_id = i;
        i++;    
    }
}

void    threads_init(t_data *data)
{
    int i;

    i = 0;
    while(i < data->n_philos)
    {
        data->philo[i].p_id = i;
        data->philo[i].full = 0;
        data->philo[i].count_meal = 0;
        give_fork(data->philo, data->forks, i, data->n_philos);
        i++;
    }
}

void    init(t_data *data)
{
    data->sim_end = 0;
    data->sync = false;
    data->philo = ret_malloc(sizeof(t_philos) * data->n_philos);
    data->forks = ret_malloc(sizeof(t_fork) * data->n_philos);
    mutex_handle(&data->data_mutex, M_INIT);
	mutex_handle(&data->write_mutex, M_INIT);
    mutex_init(data);
    threads_init(data);
}