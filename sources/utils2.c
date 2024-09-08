/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:32:07 by mloureir          #+#    #+#             */
/*   Updated: 2024/09/08 14:57:44 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

 void	set_bool(pthread_mutex_t *mutex, bool *dest, bool value)
 {
	 mutex_handle(mutex, M_LOCK);
	 *dest = value;
	 mutex_handle(mutex, M_UNLOCK);
 }

 bool	get_bool(pthread_mutex_t *mutex, bool *value)
 {
	 bool	toret;
	 mutex_handle(mutex, M_LOCK);
	 toret = *value;
	 mutex_handle(mutex, M_UNLOCK);
 	return (toret);
 }

void	set_long(pthread_mutex_t *mutex, long *dest, long value)
{
	mutex_handle(mutex, M_LOCK);
	*dest = value;
	mutex_handle(mutex, M_UNLOCK);
}

bool	get_long(pthread_mutex_t *mutex, long *value)
{
	long	toret;
	mutex_handle(mutex, M_LOCK);
	toret = *value;
	mutex_handle(mutex, M_UNLOCK);
	return (toret);
}

long	chrono()
{
	struct	timeval	time;
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}