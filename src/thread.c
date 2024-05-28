/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 23:45:17 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/28 17:04:22 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void thread_launcher (t_data *data, t_philo *philo)
{
	unsigned int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		pthread_create(&philo[i].thid, NULL, routine, &philo[i]);
		i++;
	}
	return;
}