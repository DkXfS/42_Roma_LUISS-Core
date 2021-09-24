#include "header.h"

/*
**  thinking - 1
**  eating - 2
**  sleeping - 3
*/

void loop(t_phil_dat *data)
{
    data->state = 1;
    data->state_start_time = curr_time_milli();
    lock_n_print(data->print_control, "is thinking", data->id);
    pthread_mutex_lock((data->forks[data->id]));
    lock_n_print(data->print_control, "has taken a fork", data->id);
    pthread_mutex_lock((data->forks[data->rx_fork]));
    lock_n_print(data->print_control, "has taken a fork", data->id);
    data->state = 2;
    data->state_start_time = curr_time_milli();
    lock_n_print(data->print_control, "is eating", data->id);
    usleep(data->time_eat * 1000);
    pthread_mutex_unlock((data->forks[data->id]));
    pthread_mutex_unlock((data->forks[data->rx_fork]));
    data->state = 3;
    data->state_start_time = curr_time_milli();
    lock_n_print(data->print_control, "is sleeping", data->id);
    usleep(data->time_sleep * 1000);
}

void *start(void *ph_data)
{
    t_phil_dat *data = (t_phil_dat*) ph_data;
    if (data->id == data->max_philo)
        data->rx_fork = 1;
    else data->rx_fork = data->id + 1;
    while(data)
        loop(data);
    return (0);
}