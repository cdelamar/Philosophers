


/*
bool left_fork_available (t_philo *philo)
{
    bool output;

    pthread_mutex_lock(&philo->mutx_forks);
    output = philo->left_fork;
    pthread_mutex_unlock(&philo->mutx_forks);
    return (output);
}

bool right_fork_available (t_philo *philo)
{
    bool output;

    pthread_mutex_lock(&philo->mutx_forks);
    output = philo->right_fork;
    pthread_mutex_unlock(&philo->mutx_forks);
    return (output);
}

void take_left_fork (t_philo *philo)
{
    if (left_fork_available(philo))
        philo->left_fork = true;
}

void take_right_fork (t_philo *philo)
{

}*/



// check death
// check fork ?
// left / right fork

// check hunger list
// check sleep list
// >> MUTEX

// int philo_nb;	// atoi(argv[1])
// u_int64_t death_time;	// atoi(argv[2])
// u_int64_t eat_time;	// atoi(argv[3])
// u_int64_t sleep_time;	// atoi(argv[4])
// u_int64_t meal_nb; 	// atoi(argv[5]) :optionnal
// u_int64_t start_time;
/*
bool all_philos_alive (t_data *data, t_philo *philo)
{
	unsigned int    i;

	i = 0;
	while (i < data->philo_nb)
	{
		if (philo[i].state = DIE)
			return (false);
		i++;
	}
	return (true);
}

int death_crawler(t_data *data, t_philo *philo)rougon macquart
	while (i < data->philo_nb)
	{
		if (philo[i].last_eat_time < data->eat_time || philo[i].last_sleep_time < data->sleep_time)
		{
			philo[i].state = DIE;
			return(1);
		}
		i++;
	}

	return (0);
}

void *routine (void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if(take_left_fork(philo) && take_right_fork(philo))
		eating(philo);

	return;
}*/