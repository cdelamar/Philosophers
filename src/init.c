/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:29:54 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/15 17:48:55 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
t_philo create_philo(t_philo *philo, t_data *data)
{
	t_philo output;

	output.state = IDLE;
	output.alive = true;
	output.take_fork_left = false;
	output.take_fork_right = false;
	//time
	return (output);
}*/

t_data *init_data (int argc, char **argv)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	data->philo_nb = atoi(argv[1]);
	data->death_time = atoi(argv[2]);
	data->eat_time = atoi(argv[3]);
	data->sleep_time = atoi(argv[4]);
	if (argc == 6)
		data->meal_nb = atoi(argv[5]);
	data->start_time = ft_time();
	return data;
}
/*
t_philo *init_philo (t_data *data, t_philo *philo)
{
	t_philo *output;
	int		i;

	i = 0;
	output = malloc(sizeof(t_philo) * data->philo_nb); // +1 ?

	while(i < data->philo_nb)
	{
		output[i] = create_philo(&output[i], data);
	}
}*/