#include "philo.h"

int is_number(char c)
{
	return (c >= '0' && c <= '9');
}

bool valid_inputs(int argc, char **argv, t_data *data, t_philo *philo)
{
	int	i;
	int	j;

	i = 1;
	while(i < argc)
	{
		j = 0;
		while(argv[i][j])
		{
			if (is_number(argv[i][j]) == 0)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
