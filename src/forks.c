/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 06:00:01 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/27 13:43:59 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
int take_fork (t_philo *philo)
{
   if (philo->index % 2 == 0)
   {
		pthread_mutex_lock(&philo->mx_left_fork);
		print_philo(philo, "has taken his left fork\n");
		pthread_mutex_lock(philo->mx_right_fork);
		print_philo(philo, "has taken his right fork\n");
   }
   else
   {
		pthread_mutex_lock(philo->mx_right_fork);
		print_philo(philo, "has taken his RIGHT fork\n");
		pthread_mutex_lock(&philo->mx_left_fork);
		print_philo(philo, "has taken his LEFT fork\n");
   }

   return(1);
}
*/
int take_fork (t_philo *philo)
{
		pthread_mutex_lock(philo->mx_right_fork);
		print_philo(philo, "has taken his RIGHT fork\n");
		pthread_mutex_lock(&philo->mx_left_fork);
		print_philo(philo, "has taken his LEFT fork\n");

	   return(1);
}
