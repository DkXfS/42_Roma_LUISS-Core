#include "header.h"

int main(int argc, char** argv)
{
    int philo_num;
    int temp;
    t_phil_dat **ph_dat_v;
    pthread_mutex_t **forks;
    pthread_mutex_t print_control;

    if (argc < 2)
    {
        // TODO error : No arguments
    }
    else
    {
        philo_num = ft_atoi(argv[1]);
        temp = philo_num;
        ph_dat_v = malloc(philo_num * sizeof(t_phil_dat*));
        forks = malloc(philo_num * sizeof(pthread_mutex_t*));
        while(temp)
        {
            forks[temp]=malloc(sizeof(pthread_mutex_t));
            pthread_mutex_init(forks[temp], NULL);
            temp--;
        }
        while(philo_num)
        {
            *ph_dat_v = malloc(sizeof(t_phil_dat));
            (*ph_dat_v)->time_death = ft_atoi(argv[2]);
            (*ph_dat_v)->time_eat = ft_atoi(argv[3]);
            (*ph_dat_v)->time_sleep = ft_atoi(argv[4]);
            (*ph_dat_v)->print_control = print_control;
            (*ph_dat_v)->forks = forks;
            pthread_create();
        }
    }
}