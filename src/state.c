/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 05:55:22 by cdelamar          #+#    #+#             */
/*   Updated: 2024/06/03 10:36:23 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	eating(t_philo *philo)
{
	// pthread_mutex_lock(&philo->last_eat);
	philo->last_eat_time = ft_time();
	// pthread_mutex_unlock(&philo->last_eat);

	// pthread_mutex_lock(&philo->data->mx_state);
	philo->state = EAT;
	print_philo(philo, "is eating\n");
	// pthread_mutex_unlock(&philo->data->mx_state);

	usleep(philo->data->eat_time * 1000);
	pthread_mutex_unlock(&philo->mx_left_fork);
	pthread_mutex_unlock(philo->mx_right_fork);
	return (0);
}

int	sleeping(t_philo *philo)
{
	// pthread_mutex_lock(&philo->data->mx_state);
	philo->state = SLEEP;
	print_philo(philo, "is sleeping\n");
	usleep(1000 * philo->data->sleep_time); // * 1000 ?
	// pthread_mutex_unlock(&philo->data->mx_state);
	return (0);
}

int	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mx_state);
	philo->state = THINK;
	print_philo(philo, "is thinking\n");
	pthread_mutex_unlock(&philo->data->mx_state);
	return (0);
}

void	dying(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mx_reaper);
	philo->state = DIE;
	pthread_mutex_unlock(&philo->data->mx_reaper);
}
