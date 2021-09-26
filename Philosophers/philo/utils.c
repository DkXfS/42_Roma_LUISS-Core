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

void lock_n_print(pthread_mutex_t *print_mutex, char *str, int id, long int time)
{
	pthread_mutex_lock(print_mutex);
	printf("%ld %d %s\n", time, id, str);
	pthread_mutex_unlock(print_mutex);
}