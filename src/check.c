#include "philo.h"

bool check_arguments(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		error_message(INVALID_ARGC);
	if (argc == 6 && atoi(argv[5]) <= 0)
		error_message(WRONG_MEAL_NB);
	if (valid_inputs(argc, argv) == false)
		error_message(INPUT_NOT_NB);


	return (true);
}
