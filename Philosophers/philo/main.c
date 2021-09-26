#include "header.h"

void    thread_watch(t_phil_dat *ph_dat, int ph_num)
{
    int fail_bool;
    int i;

    fail_bool = 0;
    i = 0;
    while(!fail_bool)
    {
        if (i == ph_num)
            i = 0;
        if (curr_time_milli() - ph_dat[i].state_start_time >= ph_dat[i].state_death_time)
        {
            lock_n_print(ph_dat[i].print_control, "", ph_dat[i].id , ph_dat[i].state_death_time);
            fail_bool++;
            lock_n_print(ph_dat[i].print_control, "died", ph_dat[i].id, curr_time_milli() - ph_dat[i].zero_time);
        }
        i++;
    }
}

int main(int argc, char** argv)
{
    int philo_num;
    int temp;
    t_phil_dat *ph_dat_v;
    pthread_mutex_t *forks;
    pthread_mutex_t print_control;
    pthread_t *philo_tid;
    long int time_zero;

    if (argc < 5)
    {
        // TODO error : Not enough arguments
    }
    else
    {
        philo_num = ft_atoi(argv[1]);   // TODO error : not numeric
        temp = philo_num;
        ph_dat_v = malloc(philo_num * sizeof(t_phil_dat));
        forks = malloc(philo_num * sizeof(pthread_mutex_t));
        philo_tid = malloc(philo_num * sizeof(pthread_t));
        pthread_mutex_init(&print_control, NULL);
        while(temp)
        {
            pthread_mutex_init(&forks[temp--], NULL);
        }
        time_zero = curr_time_milli();
        while(temp < philo_num)
        {
            //ph_dat_v[temp] = malloc(sizeof(t_phil_dat));
            ph_dat_v[temp].id = temp + 1;
            ph_dat_v[temp].max_philo = philo_num;
            ph_dat_v[temp].time_death = ft_atoi(argv[2]);
            ph_dat_v[temp].time_eat = ft_atoi(argv[3]);
            ph_dat_v[temp].time_sleep = ft_atoi(argv[4]);
            ph_dat_v[temp].print_control = &print_control;
            ph_dat_v[temp].forks = forks;
            ph_dat_v[temp].zero_time = time_zero;
            pthread_mutex_init(&(ph_dat_v[temp].hold), NULL);
            if (argc == 6)
                ph_dat_v[temp].num_eat = ft_atoi(argv[5]);
            if (pthread_create(&philo_tid[temp], NULL, start, &ph_dat_v[temp]) != 0)
                printf("ERROR\n");
            temp++;
            usleep(50);
        }
        thread_watch(ph_dat_v, philo_num);
        free(ph_dat_v);
        free(forks);
        free(philo_tid);
    }
}