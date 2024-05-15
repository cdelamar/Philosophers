/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:29:47 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/15 05:21:37 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char *check_arguments(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return(INVALID_ARGC);
	if (argc == 6 && atoi(argv[5]) <= 0)
		return(WRONG_MEAL_NB);
	if (valid_inputs(argc, argv) == false)
		return(INPUT_NOT_NB);

	return (NULL);
}
