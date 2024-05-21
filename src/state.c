/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 05:55:22 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/21 10:15:49 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// eating
// sleeping
// dying

//if (take_fork(philo[i]))

int eating (t_philo *philo)
{
    philo->state = EAT;
    printf("philo %d is eating\n", philo->index);
    usleep(1000);
    pthread_mutex_unlock(&philo->mx_left_fork);
    pthread_mutex_unlock(philo->mx_right_fork);
    return (0);
}

int sleeping (t_philo *philo)
{
    philo->state = SLEEP;
    printf("philo %d is sleeping\n", philo->index);
    usleep(1000 * philo->data->sleep_time);
    return (0);
}

int thinking (t_philo *philo)
{
	philo->state = THINK;
	printf("philo %d is thinking\n", philo->index);
	return (0);
}

int dying (t_philo *philo)
{
    /*
        if (philo->last_meal_time > data->eat_time)
            DEAD
        state DEAD;
    */
}

