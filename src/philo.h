/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:30:08 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/17 06:17:16 by cdelamar         ###   ########.fr       */
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

typedef enum e_state
{
	IDLE = 0,
	THINK = 1,
	SLEEP = 2,
	EAT = 3,
	DIE = 4
} t_state;

typedef struct s_data
{
	unsigned int	philo_nb;	// atoi(argv[1])
	uint64_t		death_time;	// atoi(argv[2])
	uint64_t		eat_time;	// atoi(argv[3])
	uint64_t		sleep_time;	// atoi(argv[4])
	uint64_t		meal_nb; 	// atoi(argv[5]) :optionnal
	uint64_t		start_time;
} t_data;

typedef struct s_philo
{
	int				index;

	bool			alive;
	bool			left_fork;
	bool			right_fork;

	uint64_t		last_eat_time;
	uint64_t		last_sleep_time;
	uint64_t		time; // obsolete ?

	pthread_t		thid;

	pthread_mutex_t	mutx_forks;
	pthread_mutex_t	mutx_eat;
	pthread_mutex_t	mutx_die;

	t_state			state;

} t_philo;

uint64_t	ft_time();
int			is_number(char c);
void		error_message(char *str);
void		ft_putendl_fd(char *s, int fd);
bool		valid_inputs(int argc, char **argv);
bool		min_max_value(int argc, char **argv);
char		*check_arguments(int argc, char **argv);
t_data		*init_data (int argc, char **argv);

t_philo		*init_philo (t_data *data);
t_philo		create_philo(t_data *data, int is);
void		thread_launcher (t_data *data, t_philo *philo);
void		*routine (void *arg);

int			ft_atoi(const char *nptr);
uint64_t	ft_atoi64_t(const char *nptr);

bool all_philos_alive (t_data *data, t_philo *philo);

#endif