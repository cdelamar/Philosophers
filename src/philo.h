/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:30:08 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/16 03:19:42 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
#include <limits.h>

# define INVALID_ARGC	"invalid or wrong number of arguments"
# define WRONG_MEAL_NB	"pick a correct amount of times each philosopher must eat"
# define INPUT_NOT_NB	"inputs are not positives numbers"

# define TAKE_A_FORK 	"has taken a fork"
# define IS_THINKING 	"is thinking"
# define IS_SLEEPING	"is sleeping"
# define IS_EATING		"is eating"
# define IS_DEAD 		"died"

# define IDLE	0
# define THINK	1
# define SLEEP	2
# define EAT	3
# define DIE	4

// TODO : define const int variable
typedef struct s_data
{
	int 	philo_nb;	// atoi(argv[1])
	int		death_time;	// atoi(argv[2])
	int		eat_time;	// atoi(argv[3])
	int		sleep_time;	// atoi(argv[4])
	int		meal_nb; 	// atoi(argv[5]) :optionnal
	uint64_t start_time;
} t_data;

typedef struct s_philo
{
	int				state;
	int				index;
	bool			alive;
	bool			take_fork_left;
	bool			take_fork_right;
	u_int64_t		time;
	pthread_t		thid;
	pthread_mutex_t	mutx_sleep_t;
	pthread_mutex_t	mutx_eat_t;
	pthread_mutex_t	mutx_die_t;

	t_data			*data; // testing this concept
} t_philo;

uint64_t	ft_time();
int			is_number(char c);
void		error_message(char *str);
void		ft_putendl_fd(char *s, int fd);
bool		valid_inputs(int argc, char **argv);
bool		min_max_value(int argc, char **argv);
char		*check_arguments(int argc, char **argv);
t_data		*init_data (int argc, char **argv);

void		init_philo (t_data *data, t_philo *philo);
t_philo		create_philo(t_data *data);
void		thread_launcher (t_data *data, t_philo *philo);
void		*routine (void *arg);

#endif