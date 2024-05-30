/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 23:45:17 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/30 19:25:34 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	ft_time(void)
{
    struct	timeval  tv;
    uint64_t	output;

    gettimeofday (&tv, NULL);
    output = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
    return (output);
}

void	thread_launcher(t_data *data, t_philo *philo)
{
	unsigned int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		pthread_create(&philo[i].thid, NULL, routine, &philo[i]);
		usleep(1000); //FIXED by jcario
		i++;
	}
	i = 0;
	while (i < data->philo_nb)
	{
		pthread_join(philo[i].thid, NULL);
		i++;
	}
	return ;
}