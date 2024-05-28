/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 00:27:43 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/28 17:05:34 by cdelamar         ###   ########.fr       */
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

	if (philo->data->death == false)
	{
		time = ft_time() - philo->data->start_time;
		pthread_mutex_lock(&philo->data->mx_output);
		printf("%lu : philo %d %s",time , philo->index, str);
		pthread_mutex_unlock(&philo->data->mx_output);
	}
	else
		return;
}

void	death_print(t_philo *philo, char *str)
{
	uint64_t time;

	time = ft_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->mx_output);
	printf("%lu : philo %d %s",time , philo->index, str);
	pthread_mutex_unlock(&philo->data->mx_output);
	return;
}

void *routine (void *arg) // TODO : stop routine to join all thread
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->data->death == true) // mutex // (mx_die ?)
			break;
		if (take_fork(philo) == 1)
			eating(philo);
		else if (philo->state == EAT)
		{
			if (philo->data->death == true)
				break;
			sleeping(philo);
		}
		else
		{
			if (philo->data->death == true)
				break;
			thinking(philo);
		}
	}
	return (NULL);
}
