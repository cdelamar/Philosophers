/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:30:01 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/15 15:54:10 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

int is_number(char c)
{
	return (c >= '0' && c <= '9');
}

bool valid_inputs(int argc, char **argv)
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
// TODO : FIX (bigger numbers than 2147483647 are passing sometimes)
bool min_max_value(int argc, char **argv)
{
	int i;

	i = 0;
	while (i < argc)
	{
		if (atoi(argv[i]) > 2147483647)
			return (false);
		i++;
	}
	return (true);
}



