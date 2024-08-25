/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:17:10 by miguel            #+#    #+#             */
/*   Updated: 2024/08/25 21:19:48 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void    print_all(t_data *data, t_fork *forks, t_philos *philo)
{
    int i;

    i = 0;
    while(i < data->n_philos)
    {
        ft_printf("| [%d] & %p |", forks[i].f_id, &forks[i]);
        i++;
    }
    i = 0;
    ft_printf("\n--------------------\n");
    while(i < data->n_philos)
    {
        ft_printf("| [%d] & %p & %p |", philo[i].p_id, philo[i].lfork, 
        philo[i].rfork);
        i++;
    }
    ft_printf("\n--------------------\n");
}