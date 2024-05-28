/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:29:57 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/28 17:05:59 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int nobody_died (t_philo *philo)
{
	unsigned int i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&philo[i].data->mx_die);
		if (philo[i].last_eat_time > philo->data->death_time)
		{
			philo[i].state = DIE;
			philo[i].data->death = true;			// TODO : FIX // chiant
			pthread_mutex_unlock(&philo[i].data->mx_die);
			death_print(&philo[i], "has died\n");	// deathprint
			return(1) ;
		}
		pthread_mutex_unlock(&philo[i].data->mx_die);
		i++;
		if (i >= philo->data->philo_nb)
			i = 0;
	}
}

void	error_message(char *str)
{
	ft_putendl_fd(str, STDERR_FILENO);
}

int main (int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	data = NULL;
	philo = NULL;
	if (check_arguments(argc, argv) != NULL)
	{
		error_message(check_arguments(argc, argv));
		return (EXIT_FAILURE);
	}
	data = init_data(argc, argv);
	if (data == NULL)
		return (EXIT_FAILURE);
	philo = init_philo(data);
	thread_launcher(data, philo);
	if (nobody_died(philo) == 1)
	{
		unsigned int i = 0;
		while (i < data->philo_nb)
		{
			pthread_join(philo[i].thid, NULL);
			i++;
		}
	}
		free(data);
		free(philo);
		return (EXIT_SUCCESS);
}
