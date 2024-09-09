/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:52:04 by mloureir          #+#    #+#             */
/*   Updated: 2024/09/09 11:52:05 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdbool.h>
#include "includes/42_libft/libft.h"
#include "includes/42_ftprintf/ft_printf/ft_printf.h"
#define M_INIT 1
#define M_DESTROY 2
#define M_LOCK 3
#define M_UNLOCK 4
#define P_FORK 1
#define P_EATING 2
#define P_SLEEP 3
#define P_THINK 4
#define P_DEAD 5
#define F "\033[35;4m"
#define N "\033[0m"
