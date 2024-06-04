/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:29:57 by cdelamar          #+#    #+#             */
/*   Updated: 2024/06/03 17:17:17 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// --fair-sched=yes
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	ft_free(t_philo *philo, t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < philo->data->philo_nb)
	{
		pthread_mutex_destroy(&philo[i].mx_left_fork);
		i++;
	}
	pthread_mutex_destroy(&data->mx_die);
	pthread_mutex_destroy(&data->mx_output);
	pthread_mutex_destroy(&data->mx_finished);
	pthread_mutex_destroy(&data->mx_reaper);
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
