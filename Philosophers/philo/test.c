#include "header.h"

int main()
{
    struct timeval cur_time;
    gettimeofday(&cur_time, NULL);
    printf("seconds : %ld\tmicrosecond : %d\n", cur_time.tv_sec, cur_time.tv_usec);
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

pthread_t philo_tid[n];
t_phil_dat philo_dat[n];
free(philo_dat[n]);
pthread_detach(philo_tid[n]);

-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/


