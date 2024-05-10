#include "philo.h"

t_data *init_malloc_data (int argc, char **argv, t_data *data)
{
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);

	data->philo_nb = atoi(argv[1]);
	data->death_time = (u_int64_t) atoi(argv[2]);
	data->eat_time = (u_int64_t) atoi(argv[3]);
	data->sleep_time = (u_int64_t) atoi(argv[4]);
	if (argc == 6)
		data->meal_nb = atoi(argv[5]);

	return (data);
}