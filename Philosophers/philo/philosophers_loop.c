#include "header.h"

/*
**  thinking - 1
**  eating - 2
**  sleeping - 3
*/

int loop(t_phil_dat **data)
{
    lock_n_print((*data)->common, "is thinking", (*data)->id, curr_time_milli() - (*data)->common->zero_time);
    if ((*data)->common->stop_bool == 'x')
        return (0);
    pthread_mutex_lock(&((*data)->common->forks[(*data)->id]));
    lock_n_print((*data)->common, "has taken a fork", (*data)->id, curr_time_milli() - (*data)->common->zero_time);
    if ((*data)->common->stop_bool == 'x')
        return (0);
    pthread_mutex_lock(&((*data)->common->forks[(*data)->rx_fork]));
    lock_n_print((*data)->common, "has taken a fork", (*data)->id, curr_time_milli() - (*data)->common->zero_time);
    (*data)->last_eat_time = curr_time_milli();
    if ((*data)->common->stop_bool == 'x')
        return (0);
    lock_n_print((*data)->common, "is eating", (*data)->id, curr_time_milli() - (*data)->common->zero_time);
    usleep((*data)->common->eat_time * 1000);
    pthread_mutex_unlock(&((*data)->common->forks[(*data)->id]));
    pthread_mutex_unlock(&((*data)->common->forks[(*data)->rx_fork]));
    if ((*data)->common->stop_bool == 'x')
        return (0);
    lock_n_print((*data)->common, "is sleeping", (*data)->id, curr_time_milli() - (*data)->common->zero_time);
    usleep((*data)->common->sleep_time * 1000);
    return (1);
}

void *start(void *ph_data)
{
    t_phil_dat *data = (t_phil_dat*) ph_data;
    if (data->id == data->common->philo_num)
        data->rx_fork = 1;
    else
        data->rx_fork = data->id + 1;
    data->last_eat_time = curr_time_milli();
    while(loop(&data));
    pthread_mutex_lock(&(data->common->print_control));     ////
    printf("ended : %d\n", data->id);                       ////
    pthread_mutex_unlock(&(data->common->print_control));   ////
    return (0);
}