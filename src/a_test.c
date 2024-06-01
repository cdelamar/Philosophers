#include "../includes/philo.h"
/*
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
	eating(philo);
	philo->meal++;
	if (philo->meal == philo->meal_nb && philo->meal_nb != -1)
	{
		pthread_mutex_lock(&philo->data->mx_finished);
		philo->data->philo_finished++;
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
	sleeping(philo);
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

// this one should be optimized
int	check_loop(t_philo *philo)
{
	if (death_check(philo))
		return (1);
	if (take_fork(philo) == 1)
	{
		if (eating_and_check_meal(philo) == 1)
			return (1);
	}
	pthread_mutex_lock(&philo->data->mx_state);
	if (philo->state == EAT && check_eat_state(philo) == 1)
	{
		pthread_mutex_unlock(&philo->data->mx_state);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->mx_state);
		if (death_check(philo) == true)
			return (1);
		thinking(philo);
	}
	return (0);
}*/