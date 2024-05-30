/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 00:27:43 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/30 19:20:55 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo(t_philo *philo, char *str)
{
	uint64_t	time;

	if (philo->data->death == false)
	{
		time = ft_time() - philo->data->start_time;
		pthread_mutex_lock(&philo->data->mx_output);
		printf("%lu : philo %d %s", time, philo->index, str);
		pthread_mutex_unlock(&philo->data->mx_output);
	}
	else
		return ;
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

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->data->death == true)
			break ;
		if (take_fork(philo) == 1)
		{
			if (eating_and_check_meal(philo) == 1)
				return (NULL);
		}
		if (philo->state == EAT && check_eat_state(philo) == 1)
			break ;
		else
		{
			if (philo->data->death == true)
				break ;
			thinking(philo);
		}
	}
	return (NULL);
}

int	eating_and_check_meal(t_philo *philo)
{
	eating(philo);
	philo->meal++;
	if (philo->meal == philo->meal_nb && philo->meal_nb != -1)
	{
		pthread_mutex_lock(&philo->data->mx_finished);
		philo->data->philo_finished++;
		pthread_mutex_unlock(&philo->data->mx_finished);
		return (1);
	}
	return (0);
}

int	check_eat_state(t_philo *philo)
{
	if (philo->data->death == true)
		return (1);
	sleeping(philo);
	return (0);
}
