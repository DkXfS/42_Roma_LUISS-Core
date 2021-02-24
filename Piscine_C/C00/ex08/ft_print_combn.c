/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 18:55:15 by apanthap          #+#    #+#             */
/*   Updated: 2020/11/29 13:34:00 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rec_print(char *ray, int n, char digit, int total)
{
	if (n == 1)
	{
		while (digit <= '9')
		{
			ray[total - n] = digit;
			write(1, ray, total);
			if (ray[0] != '9' - (total - 1))
				write(1, ", ", 2);
			digit++;
		}
	}
	else
		while (digit <= '9' - (n - 1))
		{
			ray[total - n] = digit;
			rec_print(ray, n - 1, digit + 1, total);
			digit++;
		}
}

void	ft_print_combn(int n)
{
	char num_ray[n];

	rec_print(num_ray, n, '0', n);
}
