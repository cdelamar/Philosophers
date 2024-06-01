/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 00:27:43 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/31 17:56:47 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (check_loop(philo))
			break ;
	}
	return (NULL);
}

int	check_loop(t_philo *philo)
{
	if (death_check(philo))
		return (1);
	if (take_fork(philo) == 1)
	{
		if (eating_and_check_meal(philo) == 1)
			return (1);
	}
	pthread_mutex_lock(&philo->data->mx_state);
	if (philo->state == EAT && check_eat_state(philo) == 1)
	{
		pthread_mutex_unlock(&philo->data->mx_state);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->mx_state);
		if (death_check(philo) == true)
			return (1);
		thinking(philo);
	}
	return (0);
}

void	*monitoring(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	nobody_died(philo);
	return (NULL);
}

void	nobody_died(t_philo *philo)
{
	unsigned int	i;

	i = 0;
	while (1)
	{
		// pthread_mutex_lock(&philo[i].data->mx_finished);
		if (philo->data->philo_finished >= philo->data->philo_nb) // mutex unlock ?
			return ;
		// pthread_mutex_unlock(&philo[i].data->mx_finished);
		// pthread_mutex_lock(&philo[i].data->mx_die);
		if (ft_time() - philo[i].last_eat_time >= philo->data->death_time)
		{
			dying(&philo[i]); // are the value modified ?
			philo[i].data->death = true;
			// pthread_mutex_unlock(&philo[i].data->mx_die);
			death_print(&philo[i], "has died\n");
			return ;
		}
		pthread_mutex_unlock(&philo[i].data->mx_die);
		i++;
		if (i >= philo->data->philo_nb)
			i = 0;
	}
	return ;
}
