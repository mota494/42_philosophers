/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:43:51 by mloureir          #+#    #+#             */
/*   Updated: 2024/08/26 21:17:15 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	err_code(int i)
{
	if (i == 1)
		ft_putstr_fd("Malloc error\n", 2);
	else if (i == 2)
		ft_putstr_fd("Mutex error\n", 2);
	exit(0);
}

void	err_exit(void)
{
	ft_putstr_fd("Input error\n", 2);
	exit (0);
}

void	free_exit(t_data *data)
{
	free(data->forks);
	free(data->philo);
}

int	err_check(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (strdigit(av[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}
