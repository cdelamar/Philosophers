/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 06:00:01 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/21 09:20:32 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int take_fork (t_philo *philo)
{
   if (philo->index % 2 == 0)
   {
        pthread_mutex_lock(&philo->mx_left_fork);
        printf("philo %d has taken his left fork\n", philo->index);
        pthread_mutex_lock(philo->mx_right_fork);
        printf("philo %d has taken his right fork\n", philo->index);
   }
   else
   {
    	pthread_mutex_lock(philo->mx_right_fork);
        printf("philo %d has taken his right fork\n", philo->index);
        pthread_mutex_lock(&philo->mx_left_fork);
        printf("philo %d has taken his left fork\n", philo->index);
   }
   return(1);
}
