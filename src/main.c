/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:29:57 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/30 18:55:34 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// TODO : FIX (bigger numbers than 2147483647 are passing sometimes)
// WARNING : OVERFLOW NOT HANDLED


void	nobody_died(t_philo *philo)
{
	unsigned int	i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&philo[i].data->mx_finished);
		if (philo->data->philo_finished >= philo->data->philo_nb)
			return ;
		pthread_mutex_unlock(&philo[i].data->mx_finished);
		pthread_mutex_lock(&philo[i].data->mx_die);
		if (ft_time() - philo[i].last_eat_time >= philo->data->death_time)
		{
			philo[i].state = DIE;
			philo[i].data->death = true;
			pthread_mutex_unlock(&philo[i].data->mx_die);
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

void	*monitoring(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	nobody_died(philo);
	return (NULL);
}

void	error_message(char *str)
{
	ft_putendl_fd(str, STDERR_FILENO);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	philo = NULL;
	if (check_arguments(argc, argv) != NULL)
	{
		error_message(check_arguments(argc, argv));
		return (EXIT_FAILURE);
	}
	init_data(argc, argv, &data);
	philo = init_philo(&data);
	pthread_create(&data.death_monitor, NULL, monitoring, (void *)philo);
	thread_launcher(&data, philo);
	pthread_join(data.death_monitor, NULL);
	free(philo);
	return (EXIT_SUCCESS);
}
