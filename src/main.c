#include "philo.h"

void	error_message(char *str)
{
	ft_putendl_fd(str, 1);
	exit(0);
}

int main (int argc, char **argv)
{
	t_data	*data = NULL;
	//t_philo	*philo;

	if (check_arguments(argc, argv) == true)
		printf("ok good\n");
	if (init_malloc_data(argc,argv, data) != NULL)
		printf("malloc ok\n");
	// init_data value
	free(data);
	return (0);
}