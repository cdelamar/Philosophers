/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 04:27:52 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/29 04:28:07 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
*/