/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:43:51 by mloureir          #+#    #+#             */
/*   Updated: 2024/07/02 15:43:51 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	err_exit(void)
{
	ft_putstr_fd("Input error\n", 2);
	exit (0);
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
