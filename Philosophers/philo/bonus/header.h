/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:10:29 by apanthap          #+#    #+#             */
/*   Updated: 2021/10/12 19:17:01 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <sys/time.h>
# include <semaphore.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_main
{
	int				eat_time;
	int				death_time;
	int				sleep_time;
	int				ph_num;
	int				max_eat;
	int				do_max_eat;
	int				num_eat;
	long int		zero_time;
	char			stop_bool;
}				t_main;

typedef struct s_phil_dat
{
	int			id;
	long int	last_eat_time;
	int			rx_fork;
	int			times_eaten;
	t_main		*common;
}				t_phil_dat;

/*//-_   utils   _-//*/

int			ft_atoi(const char *nptr);
long int	curr_time_milli(void);
void		ft_usleep(int time);
void		end_print(int id, t_main *common);
int			ft_isdigit(int c);
void		get_values(t_main *common, int argc, char **argv);

/*//-_   philosophers_loop   _-//*/

void		*start(void *data);

#endif
