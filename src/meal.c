/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 04:27:52 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/30 01:33:59 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


/*
void *meal_parser(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	unsigned int i;
	unsigned int output;

	i = 0;
	output = 0;
	while(1)
	{
		while(i < philo->data->philo_nb)
		{
			pthread_mutex_lock(&philo[i].data->mx_meal);
			if(philo[i].meal == philo->data->meal_nb)
				output++;
			pthread_mutex_unlock(&philo[i].data->mx_meal);
			i++;
		}
		if(output == philo->data->philo_nb)
		{
			return(NULL);
		}
		output = 0;
		i = 0;
	}
	return(NULL);

void *meals_complete(void *arg)
{
	t_philo *philo;
	philo = (t_philo *)arg;

	unsigned int	i;
	unsigned int	output;

	i = 0;
	output = 0;
	while (1)
	{
		while(i < philo->data->philo_nb)
		{
			if(philo[i].meal == philo->data->meal_nb)
				output++;
			i++;
		}
		if (output == philo->data->meal_nb)
			return;
		i = 0;
		output = 0;
	}
	return;
}

bool check_meal (t_philo *philo)
{*/

/*
	if(philo->data->meal_arg == false)
		return (false);

	unsigned int	i;
	unsigned int	output;

	i = 0;
	output = 0;

	while(i < philo->data->philo_nb)
	{
		if(philo[i].meal == philo->data->meal_nb)
			output++;
		i++;
	}
	if (output == philo->data->meal_nb)
		return (true);
	return (false);
}


int	add_meal (t_philo *philo)
{
	//mutex ?
	philo->meal += 1;
}*/
