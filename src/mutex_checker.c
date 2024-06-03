#include "../includes/philo.h"

int	take_fork(t_philo *philo)
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
	return (1);
}

int	eating_and_check_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_eat);
	eating(philo);
	pthread_mutex_unlock(&philo->last_eat);

	philo->meal++;
	if (philo->meal == philo->meal_nb && philo->meal_nb != -1)
	{
		pthread_mutex_lock(&philo->data->mx_finished);
		philo->data->meals_completed++;
		pthread_mutex_unlock(&philo->data->mx_finished);
		return (1);
	}
	return (0);
}

int	check_eat_state(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mx_die);
	if (philo->data->death == true)
	{
		pthread_mutex_unlock(&philo->data->mx_die);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->mx_die);
	sleeping(philo); // peut etre sortir ca de la fonction
	return (0);
}

int	death_check(t_philo *philo)
{
	bool	output;

	pthread_mutex_lock(&philo->data->mx_die);
	output = philo->data->death;
	pthread_mutex_unlock(&philo->data->mx_die);
	return (output);
}