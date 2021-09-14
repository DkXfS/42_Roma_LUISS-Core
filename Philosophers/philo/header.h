#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct s_philo_data
{
    int philo_id;
    pthread_mutex_t print_control;
    pthread_mutex_t fork1;
    pthread_mutex_t fork2;
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

/*//-_   TMP   _-//*/

#endif