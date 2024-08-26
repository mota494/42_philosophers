/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:17:10 by miguel            #+#    #+#             */
/*   Updated: 2024/08/26 21:20:35 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void    print_all(t_data *d, t_fork *f, t_philos *p)
{
    int i;

    i = 0;
    while(i < d->n_philos)
    {
        ft_printf("| [%d] & %p |", f[i].f_id, &f[i]);
        i++;
    }
    i = 0;
    ft_printf("\n--------------------\n");
    while(i < d->n_philos)
    {
        ft_printf("| [%d] & %p & %p |", p[i].p_id, p[i].lfork, p[i].rfork);
        i++;
    }
    ft_printf("\n--------------------\n");
}