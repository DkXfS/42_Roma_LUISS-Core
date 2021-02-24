/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:53:37 by apanthap          #+#    #+#             */
/*   Updated: 2020/11/30 13:16:17 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swapper(int *arr, int pos1, int pos2, int min_val)
{
	arr[pos1] = arr[pos2];
	arr[pos2] = min_val;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int min;
	int loop_pos;
	int count;
	int swap_pos;

	loop_pos = 0;
	while (loop_pos < size - 1)
	{
		count = loop_pos + 1;
		min = tab[loop_pos];
		swap_pos = -1;
		while (count < size)
		{
			if (tab[count] < min)
			{
				min = tab[count];
				swap_pos = count;
			}
			count++;
		}
		if (swap_pos > -1)
			swapper(tab, swap_pos, loop_pos, min);
		loop_pos++;
	}
}
