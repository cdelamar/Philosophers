/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:29:57 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/31 18:03:08 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
			// pthread_mutex_lock(&philo[i].data->mx_reaper);
			// philo[i].state = DIE;
			// pthread_mutex_unlock(&philo[i].data->mx_reaper);
			philo_died(&philo[i]);
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

void	philo_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mx_reaper);
	philo->state = DIE;
	pthread_mutex_unlock(&philo->data->mx_reaper);
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
	if (data.philo_nb == 1)
	{
		mono_philo(philo);
		return (EXIT_SUCCESS);
	}
	pthread_create(&data.death_monitor, NULL, monitoring, (void *)philo);
	thread_launcher(&data, philo);
	pthread_join(data.death_monitor, NULL);
	ft_free(philo, &data);
	free(philo);
	return (EXIT_SUCCESS);
}
