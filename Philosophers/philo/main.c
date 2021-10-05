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
        if (curr_time_milli() - ph_dat[i].last_eat_time >= ph_dat[i].common->death_time)
        {
            fail_bool++;
            lock_n_print(ph_dat[i].common, "died", ph_dat[i].id, curr_time_milli() - ph_dat[i].common->zero_time);
            ph_dat[i].common->stop_bool = 'x';
        }
        i++;
    }
}

void    set_common_param(t_main *common, int argc, char** argv)
{
    common->philo_num = ft_atoi(argv[1]);   // TODO error : not numeric
    if (common->philo_num == 0)
    {
        printf("ERROR: Invalid number of philosophers");
        exit(-1);
    }
    common->death_time = ft_atoi(argv[2]);
    common->eat_time = ft_atoi(argv[3]);
    common->sleep_time = ft_atoi(argv[4]);
    if (argc == 6)
        common->max_eat = ft_atoi(argv[5]);
    common->zero_time = curr_time_milli();
    common->stop_bool = 0;
    pthread_mutex_init(&(common->print_control), NULL);
    common->forks = malloc(common->philo_num * sizeof(pthread_mutex_t));
}

void    init_n_start_philo(t_phil_dat *ph_dat_v, pthread_t *philo_tid, t_main *common)
{
    int philo_num;

    philo_num = common->philo_num;
    while (philo_num)
            pthread_mutex_init(&(common->forks[--philo_num]), NULL);
    while (philo_num < common->philo_num)
    {
        ph_dat_v[philo_num].id = philo_num + 1;
        ph_dat_v[philo_num].common = common;
        if (pthread_create(&philo_tid[philo_num], NULL, start, &ph_dat_v[philo_num]) != 0)
            printf("pthread_create: Error creating philosopher thread no.%d\n", ph_dat_v->id);
        philo_num++;
    }
}

int main(int argc, char** argv)
{
    int temp;
    t_phil_dat *ph_dat_v;
    pthread_t *philo_tid;
    t_main common;

    if (argc < 5)
        printf("ERROR: Not enough arguments\n");
    else if (argc > 6)
        printf("ERROR: Too many arguments\n");
    else
    {
        set_common_param(&common, argc, argv);
        temp = common.philo_num;
        ph_dat_v = malloc(common.philo_num * sizeof(t_phil_dat));
        philo_tid = malloc(common.philo_num * sizeof(pthread_t));
        init_n_start_philo(ph_dat_v, philo_tid, &common);
        usleep(50);
        thread_watch(ph_dat_v, common.philo_num);
        while (temp--)
            pthread_join(philo_tid[temp], NULL);
        free(ph_dat_v);
        free(common.forks);
        free(philo_tid);
    }
}