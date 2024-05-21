/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:29:57 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/21 09:36:41 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO : get time()

#include "philo.h"

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


