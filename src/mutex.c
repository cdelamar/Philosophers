#include "../includes/philo.h"


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

int	death_check(t_philo *philo)
{
	bool	output;

	pthread_mutex_lock(&philo->data->mx_die);
	output = philo->data->death;
	pthread_mutex_unlock(&philo->data->mx_die);
	return (output);
}