/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 00:27:43 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/23 06:00:55 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t ft_time()
{
    struct timeval  tv;
    uint64_t output;

    gettimeofday(&tv, NULL);
    output = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
    return (output);
}

void	print_philo(t_philo *philo, char *str)
{
	uint64_t time;

	time = ft_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->mx_output);
	printf("%lu : philo %d %s",time , philo->index, str);
	pthread_mutex_unlock(&philo->data->mx_output);
}

void *routine (void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (take_fork(philo) == 1)
		{
			eating(philo);
			usleep(1000);
		}
		else if (philo->state == EAT)
			sleeping(philo);
		else
			thinking(philo);
	}
	return (NULL);
}