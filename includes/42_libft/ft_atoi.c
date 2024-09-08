/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:43:40 by mloureir          #+#    #+#             */
/*   Updated: 2024/09/08 14:34:55 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long    ft_atoi(const char *nptr)
{
	long	toreturn;
	long	index;
	long	pos;

	toreturn = 0;
	index = 0;
	pos = 1;
	while ((nptr[index] >= 9 && nptr[index] <= 13) || nptr[index] == 32)
		index++;
	if (nptr[index] == '-' || nptr[index] == '+')
	{
		if (nptr[index] == '-')
			pos = pos * -1;
		index++;
	}
	while (nptr[index] >= 48 && nptr[index] <= 57)
	{
		toreturn = toreturn * 10;
		toreturn = toreturn + (nptr[index] - 48);
		index++;
	}
	return (toreturn * pos);
}
