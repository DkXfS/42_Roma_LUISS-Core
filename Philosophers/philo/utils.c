#include "header.h"

int	ft_atoi(const char *nptr)
{
	int num;
	int minus;

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

long int curr_time_milli()
{
	struct timeval time;

    gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(int time)
{
	long int end_time;

	end_time = curr_time_milli() + time;
	time/=10;
	while(curr_time_milli() < end_time)
		usleep(time);
}

void	lock_n_print(t_main *common, char *str, int id, long int time)
{
	pthread_mutex_lock(&(common->print_control));
	if (common->stop_bool != 'x')
		printf("%ld %d %s\n", time, id, str);
	pthread_mutex_unlock(&(common->print_control));
}

void	end_print(int id, t_main *common)
{
	pthread_mutex_lock(&(common->print_control));
	common->stop_bool = 'x';
	//pthread_mutex_unlock(&(common->forks[ph_dat[i].rx_fork]));
	pthread_mutex_unlock(&(common->forks[id - 1]));
	printf("%ld %d %s\n", curr_time_milli() - common->zero_time, id, "died");
	pthread_mutex_unlock(&(common->print_control));
}