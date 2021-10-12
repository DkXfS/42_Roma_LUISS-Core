/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:13:55 by apanthap          #+#    #+#             */
/*   Updated: 2021/10/12 19:16:23 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	thread_watch(t_phil_dat *ph_dat, int ph_num)
{
	int	i;

	i = 0;
	while (!ph_dat[i].common->stop_bool)
	{
		if (curr_time_milli() - ph_dat[i].last_eat_time >= \
				ph_dat[i].common->death_time && (!ph_dat[i].common->do_max_eat \
					|| ph_dat[i].times_eaten < ph_dat[i].common->max_eat))
			end_print(ph_dat[i].id, ph_dat[i].common);
		if (ph_dat[i].common->max_eat > 0 && ph_dat[i].common->num_eat >= \
				ph_dat[i].common->philo_num)
		{
			pthread_mutex_lock(&(ph_dat[i].common->print_control));
			ph_dat[i].common->stop_bool = 'x';
			pthread_mutex_unlock(&(ph_dat[i].common->forks[ph_dat[i].id - 1]));
			printf("%ld %s %d %s\n", curr_time_milli() - ph_dat[i].\
					common->zero_time, "all philosophers have eaten", \
					ph_dat[i].common->max_eat, "times");
			pthread_mutex_unlock(&(ph_dat[i].common->print_control));
		}
		i++;
		if (i >= ph_num)
			i = 0;
	}
}

void	init_n_strt_ph(t_phil_dat *ph_dat, pthread_t *ph_tid, t_main *common)
{
	int	ph_num;

	ph_num = common->philo_num;
	while (ph_num)
		pthread_mutex_init(&(common->forks[--ph_num]), NULL);
	while (ph_num < common->philo_num)
	{
		ph_dat[ph_num].id = ph_num + 1;
		ph_dat[ph_num].times_eaten = 0;
		ph_dat[ph_num].common = common;
		if (pthread_create(&ph_tid[ph_num], NULL, start, &ph_dat[ph_num]) != 0)
			printf("pthread_create: Error creating thread no.%d\n", \
					ph_dat[ph_num].id);
		usleep(50);
		ph_num++;
	}
}

int	check_alpharg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("ERROR: Non numeric arguments present\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	set_common_param(t_main *common, int argc, char **argv)
{
	if (!check_alpharg(argc, argv))
	{
		get_values(common, argc, argv);
		if (common->philo_num < 1 || common->death_time < 1 || \
				common->eat_time < 1 || (common->do_max_eat && \
					common->max_eat < 1) || common->sleep_time < 1)
		{
			printf("ERROR: Invalid arguments\n");
			return (1);
		}
		common->zero_time = curr_time_milli();
		common->stop_bool = 0;
		common->num_eat = 0;
		pthread_mutex_init(&(common->print_control), NULL);
		common->forks = malloc(common->philo_num * sizeof(pthread_mutex_t));
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int			temp;
	t_phil_dat	*ph_dat_v;
	pthread_t	*philo_tid;
	t_main		common;

	if (argc < 5)
		printf("ERROR: Not enough arguments\n");
	else if (argc > 6)
		printf("ERROR: Too many arguments\n");
	else
	{
		if (set_common_param(&common, argc, argv))
			return (1);
		temp = common.philo_num;
		ph_dat_v = malloc(common.philo_num * sizeof(t_phil_dat));
		philo_tid = malloc(common.philo_num * sizeof(pthread_t));
		init_n_strt_ph(ph_dat_v, philo_tid, &common);
		thread_watch(ph_dat_v, common.philo_num);
		while (temp--)
			pthread_join(philo_tid[temp], NULL);
		free(ph_dat_v);
		free(common.forks);
		free(philo_tid);
	}
}
