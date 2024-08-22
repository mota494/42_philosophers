/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:31:35 by mloureir          #+#    #+#             */
/*   Updated: 2024/08/22 22:08:15 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*test_thread(void *philo)
{
	t_philos	*filo;

	filo = (t_philos *)philo;
	printf("%d \n", filo->data.t_die);
	return (NULL);
}

void	thread_create(t_philos *philo)
{
	int	i;

	philo->threads = malloc(sizeof(pthread_t) * philo->data.n_philos);
	i = 0;
	while (i < philo->data.n_philos)
	{
		pthread_create(&philo->threads[i], NULL, &test_thread, &philo);
		i++;
	}
	i = 0;
	while (i < philo->data.n_philos)
	{
		pthread_join(philo->threads[i], NULL);
		i++;
	}
}

void	pass_args(int ac, char **av, t_philos *philo)
{
	philo->data.n_philos = ft_atoi(av[1]);
	philo->data.t_die = ft_atoi(av[2]);
	philo->data.t_eat = ft_atoi(av[3]);
	philo->data.t_sleep = ft_atoi(av[4]);
	if (ac > 5)
		philo->data.n_must_eat = ft_atoi(av[5]);
	else
		philo->data.n_must_eat = 0;
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
