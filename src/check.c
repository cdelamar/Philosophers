#include "philo.h"

bool check_arguments(int argc, char **argv, t_data *data, t_philo *philo)
{
	if (argc < 5 || argc > 6)
		error_message(INVALID_ARGC);
	if (argc == 6 && argv[5] <= 0)
		error_message(WRONG_MEAL_NB);
	if (valid_inputs == false)
		error_message(INPUT_NOT_NB);


	return (true);
}
