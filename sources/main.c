/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:31:35 by mloureir          #+#    #+#             */
/*   Updated: 2024/09/08 14:22:09 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	pass_args(int argc, char **argv, t_data *data)
{
	data->n_philos = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (argc > 5)
		data->n_must_eat = ft_atoi(argv[5]);
	else
		data->n_must_eat = -1;
}

void	free_all(t_data *data)
{
	mutex_handle(&data->data_mutex, M_DESTROY);
	mutex_handle(&data->write_mutex, M_DESTROY);
	mutex_handle(&data->philo->philo_mutex, M_DESTROY);
	mutex_handle(&data->forks->fork, M_DESTROY);
	free(data->philo);
	free(data->forks);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6 || err_check(argc, argv) == 0)
		err_exit();
	pass_args(argc, argv, &data);
	if (data.n_philos <= 0 || data.n_must_eat == 0)
		err_exit();
	init(&data);
	sim_start(&data);
	free_all(&data);
	return (0);
}
