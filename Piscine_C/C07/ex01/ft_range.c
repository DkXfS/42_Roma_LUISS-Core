/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:32:51 by apanthap          #+#    #+#             */
/*   Updated: 2020/12/09 19:33:16 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_range(int min, int max)
{
	int *start;

	if (min >= max)
		return ((int*)NULL);
	int *arr = (int*)malloc((max - min) * sizeof(int));
	if (!arr)
		return ((int*)NULL);
	start = arr;
	while(min < max)
	{
		*arr = min;
		min++;
		arr++;
	}
	return (start);
}
