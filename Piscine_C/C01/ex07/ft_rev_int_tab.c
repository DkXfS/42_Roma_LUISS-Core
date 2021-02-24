/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 11:24:25 by apanthap          #+#    #+#             */
/*   Updated: 2020/11/30 12:53:24 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int cp_size;
	int temp;

	size--;
	cp_size = size;
	while (size >= (cp_size + 1) / 2)
	{
		temp = tab[size];
		tab[size] = tab[cp_size - size];
		tab[cp_size - size] = temp;
		size--;
	}
}
