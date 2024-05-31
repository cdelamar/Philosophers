/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:30:01 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/30 23:38:13 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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

int	is_number(char c)
{
	return (c >= '0' && c <= '9');
}

bool	valid_inputs(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (is_number(argv[i][j]) == 0)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	min_max_value(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (atoi(argv[i]) > 2147483647)
			return (false);
		i++;
	}
	return (true);
}

uint64_t	ft_atoi64_t(const char *nptr)
{
	uint64_t	num;
	int			i;

	num = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return (num);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	return (num * sign);
}

long	ft_atol(const char *str)
{
	long int	nb;
	int			sign;

	nb = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (sign * nb);
}
