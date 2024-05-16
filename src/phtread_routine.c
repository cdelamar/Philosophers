/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phtread_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 23:45:17 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/16 02:23:07 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine (void *arg)
{
	t_philo *philo = (t_philo*) arg;
	printf("Philo number %d has arrived !\n", philo->index);
	return (NULL);
}

void thread_launcher (t_data *data, t_philo *philo)
{
	int i;

	i = 0;
	while (i < data->philo_nb)
	{
		pthread_create(philo[i].thid, NULL, routine, &philo[i]);
		usleep(1000);
		i++;
	}
	i = 0;
	while (i < data->philo_nb)
	{
		pthread_join(philo[i].thid, NULL);
		i++;
	}
}