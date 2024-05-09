#include "philo.h"

void	error_message(char *str)
{
	ft_putendl_fd(str, 1);
	exit(0);
}

int main (int argc, char **argv)
{
	//t_data	*data;
	//t_philo	*philo;

	if (check_arguments(argc, argv) == true)
		printf("ok good\n");
	// init_data value
	return (0);
}