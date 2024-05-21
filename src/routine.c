/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 00:27:43 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/21 09:34:23 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine (void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (take_fork(philo) == 1)
		eating(philo);
	return (NULL);
}