/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:52:06 by miguel            #+#    #+#             */
/*   Updated: 2024/08/25 18:23:03 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void    init(t_data *data)
{
    int i;

    i = 0;
    data->sim_end = 0;
    data->philo = ret_malloc(sizeof(t_philos) * data->n_philos);
    data->forks = ret_malloc(sizeof(t_fork) * data->n_philos);
    while (i < data->n_philos)
    {
        mutex_handle(&data->forks[i].fork, M_INIT);
        i++;
    }
}