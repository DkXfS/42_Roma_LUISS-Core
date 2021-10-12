/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:17:40 by apanthap          #+#    #+#             */
/*   Updated: 2021/10/12 19:17:42 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	get_values(t_main *common, int argc, char **argv)
{
	common->philo_num = ft_atoi(argv[1]);
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
}
