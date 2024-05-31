/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 23:45:17 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/31 17:27:15 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

uint64_t	ft_time(void)
{
	struct timeval	tv;
	uint64_t		output;

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
		usleep(1000);
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

void	print_philo(t_philo *philo, char *str)
{
	uint64_t	time;

	pthread_mutex_lock(&philo->data->mx_die);
	if (philo->data->death == false)
	{
		time = ft_time() - philo->data->start_time;
		pthread_mutex_lock(&philo->data->mx_output);
		printf("%lu : philo %d %s", time, philo->index, str);
		pthread_mutex_unlock(&philo->data->mx_output);
		pthread_mutex_unlock(&philo->data->mx_die);

	}
	else
	{
		pthread_mutex_unlock(&philo->data->mx_die);
		return ;
	}
}

void	death_print(t_philo *philo, char *str)
{
	uint64_t	time;

	time = ft_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->mx_output);
	printf("%lu : philo %d %s", time, philo->index, str);
	pthread_mutex_unlock(&philo->data->mx_output);
	return ;
}

void	mono_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->mx_left_fork);
	print_philo(philo, "has taken his left fork\n");
	usleep(philo->data->death_time * 1000);
	pthread_mutex_unlock(&philo->mx_left_fork);
	death_print(philo, "has died\n");
	return ;
}
