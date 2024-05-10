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

# define INVALID_ARGC	"invalid or wrong number of arguments"
# define WRONG_MEAL_NB	"pick a correct amount of times each philosopher must eat"
# define INPUT_NOT_NB	"inputs are not positives numbers"

# define TAKE_A_FORK 	"has taken a fork"
# define IS_THINKING 	"is thinking"
# define IS_SLEEPING	"is sleeping"
# define IS_EATING		"is eating"
# define IS_DEAD 		"died"

# define THINK	0
# define SLEEP	1
# define EAT	2
# define DIE	3

typedef struct s_data
{
	int philo_nb;	// atoi(argv[1])
	u_int64_t death_time;	// atoi(argv[2])
	u_int64_t eat_time;	// atoi(argv[3])
	u_int64_t sleep_time;	// atoi(argv[4])
	u_int64_t meal_nb; 	// atoi(argv[5]) :optionnal
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

int		is_number(char c);
t_data		*init_malloc_data (int argc, char **argv, t_data *data);

void	error_message(char *str);
void	ft_putendl_fd(char *s, int fd);

bool	valid_inputs(int argc, char **argv);
bool	check_arguments(int argc, char **argv);

#endif