/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 05:55:22 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/21 09:17:52 by cdelamar         ###   ########.fr       */
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
