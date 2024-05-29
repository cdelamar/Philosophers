/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:29:57 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/29 02:57:34 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *nobody_died (void *arg)
{
	unsigned int i;
	t_philo *philo;

	i = 0;
	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&philo[i].data->mx_die);
		if (ft_time() - philo[i].last_eat_time >= philo->data->death_time) // THIS IS WHERE SHITS HAPPENS
		{
			printf("\n\n\n\n ----- LE DECES ----- \n\n\n\n");
			philo[i].state = DIE;
			philo[i].data->death = true;			// FIXED : boolean
			pthread_mutex_unlock(&philo[i].data->mx_die);
			death_print(&philo[i], "has died\n");	// deathprint OK
			return NULL ;
		}
		pthread_mutex_unlock(&philo[i].data->mx_die);
		i++;
		if (i >= philo->data->philo_nb)
			i = 0;
	}
	return NULL;
}

void	error_message(char *str)
{
	ft_putendl_fd(str, STDERR_FILENO);
}

int main (int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;
	pthread_t death_monitor;

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
	philo = init_philo(data, argc);
	pthread_create(&death_monitor, NULL, nobody_died, (void *)philo);
	thread_launcher(data, philo);
	pthread_join(death_monitor, NULL);
	free(data);
	free(philo);
	return (EXIT_SUCCESS);
}
