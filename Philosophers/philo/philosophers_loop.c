/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:14:14 by apanthap          #+#    #+#             */
/*   Updated: 2021/10/12 15:14:17 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	fork_free_exit(t_phil_dat *data)
{
	pthread_mutex_unlock(&((data->common->forks)[data->id - 1]));
	pthread_mutex_unlock(&((data->common->forks)[data->rx_fork]));
	return (0);
}

void	lock_n_print(t_main *common, char *str, int id)
{
	pthread_mutex_lock(&(common->print_control));
	if (common->stop_bool != 'x')
		printf("%ld\t%d\t%s\n", curr_time_milli() - common->zero_time, id, str);
	pthread_mutex_unlock(&(common->print_control));
}

int	loop(t_phil_dat **data)
{
	lock_n_print((*data)->common, "is thinking", (*data)->id);
	pthread_mutex_lock(&(((*data)->common->forks)[((*data)->id) - 1]));
	lock_n_print((*data)->common, "has taken a fork", (*data)->id);
	pthread_mutex_lock(&(((*data)->common->forks)[(*data)->rx_fork]));
	lock_n_print((*data)->common, "has taken a fork", (*data)->id);
	if ((*data)->common->stop_bool == 'x')
		return (fork_free_exit(*data));
	(*data)->last_eat_time = curr_time_milli();
	lock_n_print((*data)->common, "is eating", (*data)->id);
	usleep((*data)->common->eat_time * 1000);
	pthread_mutex_unlock(&(((*data)->common->forks)[((*data)->id) - 1]));
	pthread_mutex_unlock(&(((*data)->common->forks)[(*data)->rx_fork]));
	(*data)->times_eaten++;
	if ((*data)->common->do_max_eat && (*data)->times_eaten >= \
			(*data)->common->max_eat)
	{
		(*data)->common->num_eat++;
		return (0);
	}
	if ((*data)->common->stop_bool == 'x')
		return (0);
	lock_n_print((*data)->common, "is sleeping", (*data)->id);
	usleep((*data)->common->sleep_time * 1000);
	return (1);
}

void	*start(void *ph_data)
{
	t_phil_dat	*data;

	data = (t_phil_dat *) ph_data;
	if (data->id == data->common->philo_num)
		data->rx_fork = 0;
	else
		data->rx_fork = data->id;
	data->last_eat_time = curr_time_milli();
	while (loop(&data))
		;
	//pthread_mutex_lock(&(data->common->print_control));     ////
	//printf("ended : %d\n", data->id);                       ////
	//pthread_mutex_unlock(&(data->common->print_control));   ////
	return (0);
}
