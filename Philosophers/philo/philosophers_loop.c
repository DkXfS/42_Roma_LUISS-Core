#include "header.h"

/*
**  thinking - 1
**  eating - 2
**  sleeping - 3
*/

void loop(t_phil_dat **data)
{
    pthread_mutex_lock(&((*data)->hold));
    (*data)->state_death_time = (*data)->time_death;
    (*data)->state_start_time = curr_time_milli();
    pthread_mutex_unlock(&((*data)->hold));
    lock_n_print((*data)->print_control, "is thinking", (*data)->id, curr_time_milli() - (*data)->zero_time);
    pthread_mutex_lock(&((*data)->forks[(*data)->id]));
    lock_n_print((*data)->print_control, "has taken a fork", (*data)->id, curr_time_milli() - (*data)->zero_time);
    pthread_mutex_lock(&((*data)->forks[(*data)->rx_fork]));
    lock_n_print((*data)->print_control, "has taken a fork", (*data)->id, curr_time_milli() - (*data)->zero_time);
    pthread_mutex_lock(&((*data)->hold));
    //(*data)->state_death_time = (*data)->time_eat;
    (*data)->state_start_time = curr_time_milli();
    pthread_mutex_unlock(&((*data)->hold));
    lock_n_print((*data)->print_control, "is eating", (*data)->id, curr_time_milli() - (*data)->zero_time);
    //printf("time_eat : %d\n", (*data)->time_eat);
    usleep((*data)->time_eat * 1000);
    pthread_mutex_unlock(&((*data)->forks[(*data)->id]));
    pthread_mutex_unlock(&((*data)->forks[(*data)->rx_fork]));
    pthread_mutex_lock(&((*data)->hold));
    //(*data)->state_death_time = (*data)->time_sleep;
    pthread_mutex_unlock(&((*data)->hold));
    lock_n_print((*data)->print_control, "is sleeping", (*data)->id, curr_time_milli() - (*data)->zero_time);
    //printf("time_sleep : %d\n", (*data)->time_sleep);
    usleep((*data)->time_sleep * 1000);
}

void *start(void *ph_data)
{
    t_phil_dat *data = (t_phil_dat*) ph_data;
    if (data->id == data->max_philo)
        data->rx_fork = 1;
    else
        data->rx_fork = data->id + 1;
    //printf("starting : %d\n", data->id);
    while(data)
        loop(&data);
    printf("ended : %d\n", data->id);
    return (0);
}