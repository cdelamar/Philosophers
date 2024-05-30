/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:29:54 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/30 18:52:46 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*check_arguments(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (INVALID_ARGC);
	if (argc == 6 && atoi(argv[5]) <= 0)
		return (WRONG_MEAL_NB);
	if (min_max_value(argc, argv) == false)
		return (INVALID_ARGC);
	if (valid_inputs(argc, argv) == false)
		return (INPUT_NOT_NB);
	return (NULL);
}

t_philo	create_philo(t_data *data, int i)
{
	t_philo	philo;

	philo.state = IDLE;
	philo.data = data;
	philo.last_eat_time = ft_time();
	philo.index = i + 1;
	philo.meal = 0;
	philo.meal_nb = data->meal_nb;
	return (philo);
}

void	init_data(int argc, char **argv, t_data *data)
{
	data->philo_nb = ft_atoi(argv[1]);
	data->death_time = ft_atoi64_t(argv[2]);
	data->eat_time = ft_atoi64_t(argv[3]);
	data->sleep_time = ft_atoi64_t(argv[4]);
	data->meal_nb = -1;
	data->philo_finished = 0;
	if (argc == 6)
		data->meal_nb = ft_atol(argv[5]);
	pthread_mutex_init(&data->mx_finished, NULL);
	data->start_time = ft_time();
	pthread_mutex_init(&data->mx_output, NULL);
	data->death = false;
	return ;
}

t_philo	*init_philo(t_data *data)
{
	unsigned int	i;
	t_philo			*philo;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->philo_nb);
	while (i < data->philo_nb)
	{
		philo[i] = create_philo(data, i);
		pthread_mutex_init(&philo[i].data->mx_die, NULL);
		pthread_mutex_init(&philo[i].mx_left_fork, NULL);
		i++;
	}
	i = 0;
	while (i < data->philo_nb)
	{
		if (i == data->philo_nb - 1)
			philo[i].mx_right_fork = &philo[0].mx_left_fork;
		else
			philo[i].mx_right_fork = &philo[i + 1].mx_left_fork;
		i++;
	}
	return (philo);
}
