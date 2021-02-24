/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:26:50 by apanthap          #+#    #+#             */
/*   Updated: 2020/12/08 19:16:15 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 != 0 && *s2 != 0 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	sort(char *ar[], int argc)
{
	int		inner_loop;
	int		loop_pos;
	int		min;
	char	*temp;

	loop_pos = 1;
	while (loop_pos < argc - 1)
	{
		min = loop_pos;
		inner_loop = loop_pos + 1;
		while (inner_loop < argc)
		{
			if (ft_strcmp(ar[inner_loop], ar[min]) < 0)
				min = inner_loop;
			inner_loop++;
		}
		temp = ar[min];
		ar[min] = ar[loop_pos];
		ar[loop_pos] = temp;
		loop_pos++;
	}
}

int		main(int argc, char *argv[])
{
	int	pos;

	sort(argv, argc);
	pos = 1;
	while (pos < argc)
	{
		while (*argv[pos])
		{
			write(1, argv[pos], 1);
			argv[pos]++;
		}
		write(1, "\n", 1);
		pos++;
	}
}
