/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:30:08 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/31 01:23:09 by cdelamar         ###   ########.fr       */
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
# define WRONG_MEAL_NB	"pick a correct value"
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
}	t_state;

typedef struct s_data
{
	pthread_t		death_monitor;
	pthread_t		meal_monitor;
	unsigned int	philo_nb;
	unsigned int	philo_finished;
	uint64_t		death_time;	// atoi(argv[2])
	uint64_t		eat_time;	// atoi(argv[3])
	uint64_t		sleep_time;	// atoi(argv[4])
	uint64_t		start_time;
	long			meal_nb;	// atoi(argv[5]) :optionnal
	pthread_mutex_t	mx_output;	//terminal_output
	pthread_mutex_t	mx_die;
	pthread_mutex_t	mx_finished;
	bool			death;		// who did this ?  // FIXED : i did
}	t_data;

typedef struct s_philo
{
	int				index;
	long			meal; // if argc 5 > -1  // if argc 6 > 0
	long			meal_nb;	// atoi(argv[5]) :optionnal
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
int			ft_atoi(const char *nptr);
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
void		ft_free (t_philo *philo, t_data *data);
void		mono_philo (t_philo *philo);
int			death_check (t_philo *philo);
int			check_loop (t_philo *philo);

#endif