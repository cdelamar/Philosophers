#ifndef PHILO_H
# define PHILO_H

#include <semaphore.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

# define TAKE_A_FORK 	"take a fork"
# define IS_THINKING 	"is thinking"
# define IS_SLEEPING	"is sleeping"
# define IS_EATING		"is eating"
# define IS_DEAD 		"is dead"

# define THINK	0
# define SLEEP	1
# define EAT	2
# define DIE	3

typedef struct s_data
{
	int philo_nb;	// atoi(argv[1])
	int death_time;	// atoi(argv[2])
	int eat_time;	// atoi(argv[3])
	int sleep_time;	// atoi(argv[4])
	int meal_nb; 	// atoi(argv[5]) :optionnal
} t_data;

typedef struct s_philo
{
	int				fork_nb;
	u_int64_t		time;

	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;

	pthread_mutex_t	mutx_sleep_t;
	pthread_mutex_t	mutx_eat_t;
	pthread_mutex_t	mutx_die_t;

	t_data			*data; // testing this concept
} t_philo;

#endif