/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:35:51 by miguel            #+#    #+#             */
/*   Updated: 2024/08/26 22:39:52 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void    one_philo(t_data *data)
{
    
}

void    simulation(t_data *data)
{
    
}

void    thread_create(t_data *data)
{
    int i;

    i = 0;
    while (i < data->n_philos)
    {
        pthread_create(&data->philo[i].thread, NULL, &simulation, data);
        i++;
    }
}

void    sim_start(t_data *data)
{
    if (data->n_must_eat != -1 && data->n_must_eat <= 0)
        free_exit(data);
    else if (data->n_philos == 1)
        one_philo(data);
    else
        thread_create(data);
}
