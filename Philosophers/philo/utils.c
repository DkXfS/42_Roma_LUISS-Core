/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:30:40 by apanthap          #+#    #+#             */
/*   Updated: 2021/10/12 17:51:10 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_atoi(const char *nptr)
{
	int	num;
	int	minus;

	minus = 1;
	num = 0;
	while (*nptr == 32 || (*nptr > 8 && *nptr < 14))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			minus = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num *= 10;
		num += *nptr - '0';
		nptr++;
	}
	return (num * minus);
}

long int	curr_time_milli(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(int time)
{
	long int	end_time;

	end_time = curr_time_milli() + time;
	time /= 10;
	while (curr_time_milli() < end_time)
		usleep(time);
}

void	end_print(int id, t_main *common)
{
	int	rx_fork;

	rx_fork = id;
	if (id == common->philo_num)
		rx_fork = 0;
	pthread_mutex_lock(&(common->print_control));
	common->stop_bool = 'x';
	pthread_mutex_unlock(&(common->forks[rx_fork]));
	pthread_mutex_unlock(&(common->forks[id - 1]));
	printf("%ld\t%d\t%s\n", curr_time_milli() - common->zero_time, id, "died");
	pthread_mutex_unlock(&(common->print_control));
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
