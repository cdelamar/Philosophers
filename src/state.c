/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 05:55:22 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/30 19:24:29 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating(t_philo *philo)
{
	philo->last_eat_time = ft_time();
	philo->state = EAT;
	print_philo(philo, "is eating\n");
	usleep(philo->data->eat_time * 1000);
	pthread_mutex_unlock(&philo->mx_left_fork);
	pthread_mutex_unlock(philo->mx_right_fork);
	return (0);
}

int	sleeping(t_philo *philo)
{
	philo->state = SLEEP;
	print_philo(philo, "is sleeping\n");
	usleep(1000 * philo->data->sleep_time);
	return (0);
}

int	thinking(t_philo *philo)
{
	philo->state = THINK;
	print_philo(philo, "is thinking\n");
	return (0);
}
