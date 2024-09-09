/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:35:51 by miguel            #+#    #+#             */
/*   Updated: 2024/09/08 15:34:08 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*simulation(void *data)
{
	t_philos	*a_data;

	a_data = (t_philos *)data;
	sync_threads(a_data);
	while (!sim_finish(a_data->data))
	{
		grab_fork(a_data);
		eatin(a_data);
		write_status(P_SLEEP, data);
		ft_usleep(a_data->data->t_sleep);
	}
	return (NULL);
}

void	thread_create(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		pthread_create(&data->philo[i].thread, NULL, &simulation,
			&data->philo[i]);
		i++;
	}
}

void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
}

void	sim_start(t_data *data)
{
	if (data->n_must_eat != -1 && data->n_must_eat <= 0)
		free_exit(data);
	else if (data->n_philos == 1)
		ft_printf("one_philo yippie");
	else
		thread_create(data);
	data->sim_start = chrono();
	set_bool(&data->data_mutex, &data->sync, true);
	join_threads(data);
}
