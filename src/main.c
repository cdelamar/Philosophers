/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:29:57 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/23 09:00:01 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO : get time()

// TODO +++
// program a proper fork management

#include "philo.h"

bool nobody_died (t_philo *philo)
{
	//unsigned int i;

	//i = 0;
	//while (i < philo->data->philo_nb)
	//{
		//printf (">>>> L >>>> philo[%d].data->eat_time = %lu\n", i, philo[i].data->eat_time);
		//printf (">    R    > philo[%d].last_eat_time = %lu\n", i, philo[i]. last_eat_time);
	if (philo->last_eat_time > philo->data->eat_time)
		return (false);
	//	i++;
	//}
	return (true);
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
	free(data);
	free(philo);
	return (EXIT_SUCCESS);
}


