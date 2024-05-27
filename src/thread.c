/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 23:45:17 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/27 12:50:48 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
void *routine (void *arg)
{
	t_philo *philo;

	philo = (t_philo*) arg;
	printf("Philo number %d has arrived !\n", philo->index);
	usleep(10);
	return (NULL);
}*/

void thread_launcher (t_data *data, t_philo *philo)
{
	unsigned int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		pthread_create(&philo[i].thid, NULL, routine, &philo[i]);
		//usleep(100);
		i++;
	}
	i = 0;
}