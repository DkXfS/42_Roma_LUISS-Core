/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:00:07 by apanthap          #+#    #+#             */
/*   Updated: 2020/12/09 20:00:56 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	if (min >= max)
	{
		range = (int**)NULL;
		return (0);
	}
	int *arr = (int*)malloc((max - min) * sizeof(int));
	*range = arr;
	if (!arr)
		return (-1);
	while(min < max)
	{
		*arr = min;
		min++;
		arr++;
	}
	return (max - min);
}
