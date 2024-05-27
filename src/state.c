/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 05:55:22 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/27 19:04:50 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int eating (t_philo *philo)
{
    philo->state = EAT;
    // pthread_mutex_lock(&philo->data->mx_output);
	print_philo(philo, "is eating\n");
	// pthread_mutex_unlock(&philo->data->mx_output);

    philo->last_eat_time = ft_time() - philo->data->start_time;
    usleep(philo->data->eat_time * 1000);
    pthread_mutex_unlock(&philo->mx_left_fork);
    pthread_mutex_unlock(philo->mx_right_fork);
    philo->last_eat_time = ft_time() - philo->data->start_time; // or 0
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

/*
int dying (t_philo *philo)
{
    if (philo->last_eat_time > philo->data->eat_time)
        {
                philo->state = DIE;
                printf("philo %d is dead\n", philo->index);
                return (1);
        }
    return (0);
}*/
