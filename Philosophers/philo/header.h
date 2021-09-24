#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_philo_data
{
    int id;
    int max_philo;
    int state;
    int rx_fork;
    long int state_start_time;
    pthread_mutex_t *print_control;
    pthread_mutex_t **forks;
    int time_death;
    int time_eat;
    int time_sleep;
    int num_eat;
}              t_phil_dat;

typedef struct s_watcher
{

}              t_watcher;

/*//-_   utils   _-//*/

int	ft_atoi(const char *nptr);
long int curr_time_milli();
void lock_n_print(pthread_mutex_t *print_mutex, char *str, int id);

/*//-_   philosophers_loop   _-//*/

void *start(void *data);

#endif