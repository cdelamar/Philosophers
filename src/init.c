/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:29:54 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/17 02:36:33 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo create_philo(t_data *data, int i)
{
	t_philo philo;

	philo.state = IDLE;
	philo.alive = true;
	philo.take_fork_left = false;
	philo.take_fork_right = false;
	philo.time = ft_time() - data->start_time;
	philo.index = i + 1;
	return (philo);
}

t_data *init_data (int argc, char **argv)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	data->philo_nb = ft_atoi(argv[1]);
	data->death_time = ft_atoi64_t(argv[2]);
	data->eat_time = ft_atoi64_t(argv[3]);
	data->sleep_time = ft_atoi64_t(argv[4]);
	if (argc == 6)
		data->meal_nb = ft_atoi64_t(argv[5]);
	data->start_time = ft_time();
	return data;
}

t_philo *init_philo (t_data *data)
{
	unsigned int	i;
	t_philo 		*philo;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->philo_nb); // +1 ?

	while(i < data->philo_nb)
	{
		philo[i] = create_philo(data, i);
		pthread_mutex_init(&philo[i].mutx_die, NULL);
		pthread_mutex_init(&philo[i].mutx_eat, NULL);
		pthread_mutex_init(&philo[i].mutx_forks, NULL);
		i++;
		usleep(1); // why not without usleep
	}
	return (philo);
}