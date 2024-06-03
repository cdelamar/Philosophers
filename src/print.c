/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 23:45:17 by cdelamar          #+#    #+#             */
/*   Updated: 2024/06/03 09:08:40 by cdelamar         ###   ########.fr       */
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

void	print_philo(t_philo *philo, char *str)
{
	uint64_t	time;

	pthread_mutex_lock(&philo->data->mx_die);
	if (philo->data->death == false)
	{
		pthread_mutex_unlock(&philo->data->mx_die);
		time = ft_time() - philo->data->start_time;
		pthread_mutex_lock(&philo->data->mx_output);
		printf("%lu : philo %d %s", time, philo->index, str);
		pthread_mutex_unlock(&philo->data->mx_output);

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
	// printf(" ---- > ft_time() - philo[i].last_eat_time [%ld] >= philo->data->death_time [[%ld]] \n\n", (ft_time() - philo->last_eat_time), philo->data->death_time);
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
