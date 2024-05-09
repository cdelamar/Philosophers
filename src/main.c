#include "philo.h"

void	error_message(char *str)
{
	ft_putendl_fd(str, 1);
	exit(0);
}

int main (int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	if (check_arguments(argc, argv, data, philo) == true);
	printf("ok\n");
	// init_data value

}