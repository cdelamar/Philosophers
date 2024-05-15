/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letsgo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 23:04:04 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/14 23:16:20 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void *ft_routine (void *arg)
{
	printf("routine\n");
	sleep(2);
	return NULL;
}

int main()
{
	pthread_t thread_1;
	pthread_t thread_2;
	int *ptr_1 = 1;
	int *ptr_2 = 2;

	printf("letsgo\n");
	pthread_create(thread_1, ft_routine, NULL, ptr_1);
	pthread_create(thread_2, ft_routine, NULL, ptr_2);
	printf("done\n");
}