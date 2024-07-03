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

void	*test_thread(void *philo)
{
	t_philos	*filo;

	filo = (t_philos *)philo;
	ft_printf("%d", filo->n_philos);
	return (NULL);
}

void	thread_create(t_philos *philo)
{
	int	i;

	philo->threads = malloc(sizeof(pthread_t) * philo->n_philos);
	i = 0;
	while (i < philo->n_philos)
	{
		pthread_create(&philo->threads[i], NULL, &test_thread, &philo);
		i++;
	}
	i = 0;
	while (i < philo->n_philos)
	{
		pthread_join(philo->threads[i], NULL);
		i++;
	}
}

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
	thread_create(&philo);
	return (0);
}
