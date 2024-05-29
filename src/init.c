/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:29:54 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/29 23:48:00 by cdelamar         ###   ########.fr       */
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

t_philo create_philo(t_data *data, int i, int argc)
{
	t_philo philo;

	philo.state = IDLE;
	philo.data = data;
	philo.last_eat_time = ft_time(); // TODO FIX //
	philo.index = i + 1;
	if (argc == 6)
		philo.meal = 0;
	else
		philo.meal = -1;
	return (philo);
}

void init_data (int argc, char **argv, t_data *data)
{
	// t_data *data;

	// data = malloc(sizeof(t_data));
	data->philo_nb = ft_atoi(argv[1]);
	data->death_time = ft_atoi64_t(argv[2]);
	data->eat_time = ft_atoi64_t(argv[3]);
	data->sleep_time = ft_atoi64_t(argv[4]);
	if (argc == 6)
	{
		data->meal_nb = ft_atol(argv[5]);
		data->meal_arg = true;
		pthread_mutex_init(&data->mx_meal, NULL); // attention
	}
	else
		data->meal_arg = false;
	data->start_time = ft_time();
	pthread_mutex_init(&data->mx_output, NULL);
	data->death = false;
	return ;
}

t_philo *init_philo (t_data *data, int argc)
{
	unsigned int	i;
	t_philo 		*philo;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->philo_nb); // +1 ?

	while(i < data->philo_nb)
	{
		philo[i] = create_philo(data, i, argc);
		pthread_mutex_init(&philo[i].data->mx_die, NULL);
		pthread_mutex_init(&philo[i].mx_left_fork, NULL);
		i++;
	}
	i = 0;

	while(i < data->philo_nb) // FIX ?
	{
		if (i == data->philo_nb - 1)
			philo[i].mx_right_fork = &philo[0].mx_left_fork;
		else
			philo[i].mx_right_fork = &philo[i + 1].mx_left_fork;
		i++;
	}
	return (philo);
}
