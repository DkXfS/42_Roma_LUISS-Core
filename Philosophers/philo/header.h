#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_main
{
    int eat_time;
    int death_time;
    int sleep_time;
    int philo_num;
    int max_eat;
    long int zero_time;
    char stop_bool;
    pthread_mutex_t print_control;
    pthread_mutex_t *forks;
}              t_main;

typedef struct s_phil_dat
{
    int id;
    long int last_eat_time;
    int rx_fork;
    int times_eaten;
    t_main *common;
}              t_phil_dat;

/*//-_   utils   _-//*/

int	ft_atoi(const char *nptr);
long int curr_time_milli();
void lock_n_print(t_main *common, char *str, int id, long int zerot);

/*//-_   philosophers_loop   _-//*/

void *start(void *data);

#endif