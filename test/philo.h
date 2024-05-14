/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:29:35 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/13 10:29:36 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_data {

	int philo_nb;	// atoi(argv[1])
	int death_time;	// atoi(argv[2])
	int eat_time;	// atoi(argv[3])
	int sleep_time;	// atoi(argv[4])
	int meal_nb; 	// atoi(argv[5]) :optionnal

} t_data;

typedef struct s_philo {

	int fork_nb:

} t_philo;