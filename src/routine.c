/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 00:27:43 by cdelamar          #+#    #+#             */
/*   Updated: 2024/06/03 15:44:45 by cdelamar         ###   ########.fr       */
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
	if (take_fork(philo))
	{
		if (eating_and_check_meal(philo))
			return (1);
	}
	if (philo->state == EAT && check_eat_state(philo))
		return (1);
	else
	{
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

void	nobody_died(t_philo *philo) // TODO
{
	unsigned int	i;

	i = 0;
	while (1)
	{
		if (philo->data->meals_completed >= philo->data->philo_nb)
			return ;
		if (ft_time() - philo[i].last_eat_time >= philo->data->death_time)
		{
			dying(&philo[i]);
			pthread_mutex_lock(&philo->data->mx_die);
			philo[i].data->death = true;
			pthread_mutex_unlock(&philo->data->mx_die);
			death_print(&philo[i], "has died\n");
			return ;
		}
		i++;
		if (i >= philo->data->philo_nb)
			i = 0;
	}
	return ;
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
