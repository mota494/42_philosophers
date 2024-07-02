/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:31:35 by mloureir          #+#    #+#             */
/*   Updated: 2024/07/02 16:31:35 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	pass_args(int ac, char **av, t_philos *philo)
{
	philo->n_philos = ft_atoi(av[1]);
	philo->t_die = ft_atoi(av[2]);
	philo->t_eat = ft_atoi(av[3]);
	philo->t_sleep = ft_atoi(av[4]);
	if (ac > 5)
		philo->n_must_eat = ft_atoi(av[5]);
	else
		philo->n_must_eat = 0;
}

int	main(int argc, char **argv)
{
	t_philos	philo;

	if (argc < 5 || argc > 6 || err_check(argc, argv) == 0)
		err_exit();
	pass_args(argc, argv, &philo);
	printable(&philo);
	return (0);
}
