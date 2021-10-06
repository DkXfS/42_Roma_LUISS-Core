#include "header.h"

void    thread_watch(t_phil_dat *ph_dat, int ph_num)
{
    int i;

    i = 0;
    while(!ph_dat[i].common->stop_bool)
    {
        if (curr_time_milli() - ph_dat[i].last_eat_time >= ph_dat[i].common->death_time && (!ph_dat[i].common->do_max_eat || ph_dat[i].times_eaten < ph_dat[i].common->max_eat))
        {
            end_print(ph_dat[i].id, ph_dat[i].common);

            // pthread_mutex_lock(&(ph_dat[i].common->print_control));
            // ph_dat[i].common->stop_bool = 'x';
            // //pthread_mutex_unlock(&(ph_dat[i].common->forks[ph_dat[i].rx_fork]));
            // pthread_mutex_unlock(&(ph_dat[i].common->forks[ph_dat[i].id - 1]));
		    // printf("%ld %d %s\n", curr_time_milli() - ph_dat[i].common->zero_time, ph_dat[i].id, "died");
	        // pthread_mutex_unlock(&(ph_dat[i].common->print_control));
        }
        if (ph_dat[i].common->max_eat > 0 && ph_dat[i].common->num_eat >= ph_dat[i].common->philo_num)
        {
            pthread_mutex_lock(&(ph_dat[i].common->print_control));
            ph_dat[i].common->stop_bool = 'x';
            //pthread_mutex_unlock(&(ph_dat[i].common->forks[ph_dat[i].rx_fork]));
            pthread_mutex_unlock(&(ph_dat[i].common->forks[ph_dat[i].id - 1]));
		    printf("%ld %s %d %s\n", curr_time_milli() - ph_dat[i].common->zero_time, "all philosophers have eaten", ph_dat[i].common->max_eat, "times");
	        pthread_mutex_unlock(&(ph_dat[i].common->print_control));
        }
        i++;
        if (i >= ph_num)
            i = 0;
    }
}

void    set_common_param(t_main *common, int argc, char** argv)
{
    common->philo_num = ft_atoi(argv[1]);   // TODO error : not numeric
    common->death_time = ft_atoi(argv[2]);
    common->eat_time = ft_atoi(argv[3]);
    common->sleep_time = ft_atoi(argv[4]);
    if (argc == 6)
    {
        common->max_eat = ft_atoi(argv[5]);
        common->do_max_eat = 1;
    }
    else
    {
        common->do_max_eat = 0;
        common->max_eat = 0;
    }
    if (common->philo_num < 1 || common->death_time < 1 || common->eat_time < 1\
        || (common->do_max_eat && common->max_eat < 1)\
        || common->sleep_time < 1)
    {
        printf("ERROR: Invalid arguments\n");
        exit(-1);
    }
    common->zero_time = curr_time_milli();
    common->stop_bool = 0;
    common->num_eat = 0;
    pthread_mutex_init(&(common->print_control), NULL);
    common->forks = malloc(common->philo_num * sizeof(pthread_mutex_t));
}

void    init_n_strt_ph(t_phil_dat *ph_dat, pthread_t *ph_tid, t_main *common)
{
    int ph_num;

    ph_num = common->philo_num;
    while (ph_num)
            pthread_mutex_init(&(common->forks[--ph_num]), NULL);
    while (ph_num < common->philo_num)
    {
        ph_dat[ph_num].id = ph_num + 1;
        ph_dat[ph_num].times_eaten = 0;
        ph_dat[ph_num].common = common;
        if (pthread_create(&ph_tid[ph_num], NULL, start, &ph_dat[ph_num])\
             != 0)
            printf("pthread_create: Error creating thread no.%d\n", \
                    ph_dat[ph_num].id);
        usleep(50);
        ph_num++;
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
        init_n_strt_ph(ph_dat_v, philo_tid, &common);
        //usleep(50);
        thread_watch(ph_dat_v, common.philo_num);
        while (temp--)
            pthread_join(philo_tid[temp], NULL);
        free(ph_dat_v);
        free(common.forks);
        free(philo_tid);
    }
}