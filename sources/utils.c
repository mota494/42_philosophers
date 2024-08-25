/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:42:18 by mloureir          #+#    #+#             */
/*   Updated: 2024/08/25 18:08:05 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	strdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

void	*ret_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (!ret)
		err_code(1);
	return (ret);
}

void	mutex_handle(pthread_mutex_t *mtx, int opt)
{
	if (opt == M_LOCK)
		pthread_mutex_lock(mtx);
	else if (opt == M_UNLOCK)
		pthread_mutex_unlock(mtx);
	else if (opt == M_INIT)
		pthread_mutex_init(mtx, NULL);
	else if (opt == M_DESTROY)
		pthread_mutex_destroy(mtx);
	else
		err_code(2); 
}