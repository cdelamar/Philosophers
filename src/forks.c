/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 06:00:01 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/31 01:15:00 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	take_fork(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_lock(&philo->mx_left_fork);
		print_philo(philo, "has taken his left fork\n");
		pthread_mutex_lock(philo->mx_right_fork);
		print_philo(philo, "has taken his right fork\n");
	}
	else
	{
		pthread_mutex_lock(philo->mx_right_fork);
		print_philo(philo, "has taken his RIGHT fork\n");
		pthread_mutex_lock(&philo->mx_left_fork);
		print_philo(philo, "has taken his LEFT fork\n");
	}
	return (1);
}
void ft_free (t_philo *philo, t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i  < philo->data->philo_nb)
	{
		pthread_mutex_destroy(&philo[i].mx_left_fork);
		i++;
	}
	pthread_mutex_destroy(&data->mx_die);
	pthread_mutex_destroy(&data->mx_output);
	pthread_mutex_destroy(&data->mx_finished);
}