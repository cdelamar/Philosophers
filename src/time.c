/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:11:31 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/15 17:18:19 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t ft_time()
{
    struct timeval  tv;
    uint64_t output;

    gettimeofday(&tv, NULL);
    output = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
    return (output);
}