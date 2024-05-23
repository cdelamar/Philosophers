/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 05:55:22 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/23 16:04:06 by cdelamar         ###   ########.fr       */
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
	print_philo(philo, "is eating\n");
    philo->last_eat_time = ft_time();
    usleep(philo->data->eat_time * 1000);
    //setting last_eat_time
    pthread_mutex_unlock(&philo->mx_left_fork);
    pthread_mutex_unlock(philo->mx_right_fork);
    philo->last_eat_time = 0;
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
    if (philo->last_eat_time > philo->data->eat_time)
        {
                philo->state = DIE;
                printf("philo %d is dead\n", philo->index);
                return (1);
        }
    return (0);
}
