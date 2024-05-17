/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 06:00:01 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/17 18:19:30 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool left_fork_available (t_philo *philo)
{
    bool output;

    pthread_mutex_lock(&philo->mutx_forks);
    output = philo->left_fork;
    pthread_mutex_unlock(&philo->mutx_forks);
    return (output);
}

bool right_fork_available (t_philo *philo)
{
    bool output;

    pthread_mutex_lock(&philo->mutx_forks);
    output = philo->right_fork;
    pthread_mutex_unlock(&philo->mutx_forks);
    return (output);
}

void take_left_fork (t_philo *philo)
{
    if (left_fork_available(philo))
        philo->left_fork = true;
}
/*
void take_right_fork (t_philo *philo)
{

}*/