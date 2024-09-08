/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:43:39 by mloureir          #+#    #+#             */
/*   Updated: 2024/09/08 15:44:50 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

size_t	ft_usleep(size_t time)
{
	size_t	start;

	start = chrono();
	while ((chrono() - start) < time)
		usleep(time * 1e3);
	return (0);
}
