/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:29:57 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/15 17:58:46 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_message(char *str)
{
	ft_putendl_fd(str, STDERR_FILENO);
}

int main (int argc, char **argv)
{
	t_data	*data;
	//t_philo	*philo;

	//(void)philo;
	if (check_arguments(argc, argv) != NULL)
	{
		error_message(check_arguments(argc, argv));
		return (EXIT_FAILURE);
	}
	data = init_data(argc, argv);
	if (data == NULL)
		return (EXIT_FAILURE);
	printf("the code has been initialized at : %lu\n", data->start_time - ft_time());
	sleep(2);
	uint64_t test_timer2 = ft_time() - data->start_time;
	printf("2nd call at : %lu\n", test_timer2);
	return (EXIT_SUCCESS);
}