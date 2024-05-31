/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 00:27:43 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/31 01:26:48 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->philo_nb == 1)
	{
		mono_philo(philo);
		return (NULL);
	}
	while (1)
	{
		if (check_loop(philo))
			break;
	}
	return (NULL);
}

int check_loop (t_philo *philo)
{
	if (death_check(philo))
		return (1) ;
	if (take_fork(philo) == 1)
	{
		if (eating_and_check_meal(philo) == 1)
			return (1);
	}
	if (philo->state == EAT && check_eat_state(philo) == 1)
		return (1) ;
	else
	{
		if (philo->data->death == true)
			return (1) ;
		thinking(philo);
	}
	return (0);
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

int	death_check (t_philo *philo)
{
	bool output;
	pthread_mutex_lock(&philo->data->mx_die);
	output = philo->data->death;
	pthread_mutex_unlock(&philo->data->mx_die);
	return (output);
}
