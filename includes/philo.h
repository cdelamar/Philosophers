/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:30:08 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/31 18:03:03 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <semaphore.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>

# define INVALID_ARGC	"invalid or wrong number of arguments"
# define WRONG_MEAL_NB	"pick a correct meal amount"
# define INPUT_NOT_NB	"inputs are not positives numbers"
# define TAKE_A_FORK 	"has taken a fork"
# define IS_THINKING 	"is thinking"
# define IS_SLEEPING	"is sleeping"
# define IS_EATING		"is eating"
# define IS_DEAD 		"died"
# define MAX			2147483647
# define MIN 			-2147483648

typedef enum e_state
{
	IDLE = 0,
	THINK = 1,
	SLEEP = 2,
	EAT = 3,
	DIE = 4
}	t_state;

typedef struct s_data
{
	pthread_t		death_monitor;
	pthread_t		meal_monitor;
	long			philo_nb;
	unsigned int	philo_finished;
	uint64_t		death_time;
	uint64_t		eat_time;
	uint64_t		sleep_time;
	uint64_t		start_time;
	long			meal_nb;
	pthread_mutex_t	mx_output;
	pthread_mutex_t	mx_die;
	pthread_mutex_t	mx_finished;
	pthread_mutex_t	mx_state;
	pthread_mutex_t	mx_reaper;
	bool			death;
}	t_data;

typedef struct s_philo
{
	int				index;
	long			meal;
	long			meal_nb;
	uint64_t		last_eat_time;
	uint64_t		time;
	pthread_t		thid;
	pthread_mutex_t	mx_left_fork;
	pthread_mutex_t	*mx_right_fork;
	t_state			state;
	t_data			*data;
}	t_philo;

uint64_t	ft_time(void);
int			is_number(char c);
void		error_message(char *str);
void		ft_putendl_fd(char *s, int fd);
bool		valid_inputs(int argc, char **argv);
bool		min_max_value(int argc, char **argv);
char		*check_arguments(int argc, char **argv);
void		init_data(int argc, char **argv, t_data *data);
t_philo		*init_philo(t_data *data);
t_philo		create_philo(t_data *data, int i);
void		thread_launcher(t_data *data, t_philo *philo);
void		*routine(void *arg);
uint64_t	ft_atoi64_t(const char *nptr);
int			take_fork(t_philo *philo);
int			eating(t_philo *philo);
int			sleeping(t_philo *philo);
long		ft_atol(const char *str);
int			thinking(t_philo *philo);
int			dying(t_philo *philo);
void		print_philo(t_philo *philo, char *str);
void		death_print(t_philo *philo, char *str);
void		nobody_died(t_philo *philo);
void		meal_finished(t_philo *philo);
void		increment_meal(t_philo *philo);
int			meals_complete(t_philo *philo);
void		*monitoring(void *arg);
int			eating_and_check_meal(t_philo *philo);
int			check_eat_state(t_philo *philo);
void		ft_free(t_philo *philo, t_data *data);
void		mono_philo(t_philo *philo);
int			death_check(t_philo *philo);
int			check_loop(t_philo *philo);
void		philo_died(t_philo *philo);


#endif