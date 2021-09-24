#include "header.h"

void    thread_watch()
{}

int main(int argc, char** argv)
{
    int philo_num;
    int temp;
    t_phil_dat **ph_dat_v;
    pthread_mutex_t **forks;
    pthread_mutex_t print_control;
    pthread_t *philo_tid;

    if (argc < 5)
    {
        // TODO error : Not enough arguments
    }
    else
    {
        philo_num = ft_atoi(argv[1]);   // TODO error : not numeric
        temp = philo_num;
        ph_dat_v = malloc(philo_num * sizeof(t_phil_dat*));
        forks = malloc(philo_num * sizeof(pthread_mutex_t));
        philo_tid = malloc(philo_num * sizeof(pthread_t));
        while(temp)
        {
            pthread_mutex_init(forks[temp], NULL);
        }
        while(temp < philo_num)
        {
            ph_dat_v[temp] = malloc(sizeof(t_phil_dat));
            ph_dat_v[temp]->id = temp + 1;
            ph_dat_v[temp]->max_philo = philo_num;
            ph_dat_v[temp]->time_death = ft_atoi(argv[2]);
            ph_dat_v[temp]->time_eat = ft_atoi(argv[3]);
            ph_dat_v[temp]->time_sleep = ft_atoi(argv[4]);
            ph_dat_v[temp]->print_control = &print_control;
            ph_dat_v[temp]->forks = forks;
            if (argc == 6)
                ph_dat_v[temp]->num_eat = ft_atoi(argv[5]);
            pthread_create(&philo_tid[temp], NULL, start, &ph_dat_v[temp]);
        }
    }
}