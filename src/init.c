/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:29:54 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/23 18:29:48 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char *check_arguments(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return(INVALID_ARGC);
	if (argc == 6 && atoi(argv[5]) <= 0)
		return(WRONG_MEAL_NB);
	if (min_max_value(argc, argv) == false)
		return (INVALID_ARGC);
	if (valid_inputs(argc, argv) == false)
		return(INPUT_NOT_NB);
	return (NULL);
}

t_philo create_philo(t_data *data, int i)
{
	t_philo philo;

	philo.state = IDLE;
	philo.alive = true;
	philo.data = data;
	philo.last_eat_time = 0;
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
	pthread_mutex_init(&data->mx_output, NULL);
	data->die = malloc(sizeof(int));
	*data->die = 0;
	return (data);
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
		pthread_mutex_init(&philo[i].data->mx_die, NULL);
		pthread_mutex_init(&philo[i].mx_left_fork, NULL);
		i++;
		usleep(1000); // why not without usleep
	}
	i = 0;

	while(i < data->philo_nb)
	{
		if (i == data->philo_nb - 1)
			philo[i].mx_right_fork = &philo[0].mx_left_fork;
		else
			philo[i].mx_right_fork = &philo[i + 1].mx_left_fork;
		i++;
	}
	return (philo);
}
