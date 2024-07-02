/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:31:27 by mloureir          #+#    #+#             */
/*   Updated: 2024/07/02 16:31:27 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	printable(t_philos *philo)
{
	ft_printf("|---------------|------|\n");
	ft_printf("| number philos |  %d  |\n", philo->n_philos);
	ft_printf("| time to die   |  %d  |\n", philo->t_die);
	ft_printf("| time to eat   |  %d  |\n", philo->t_eat);
	ft_printf("| time to sleep |  %d  |\n", philo->t_sleep);
	ft_printf("| time must eat |  %d  |\n", philo->n_must_eat);
	ft_printf("|---------------|------|\n");
}
