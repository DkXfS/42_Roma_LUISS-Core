/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:00:34 by apanthap          #+#    #+#             */
/*   Updated: 2020/12/09 16:02:25 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int lst_dg;
	int i;

	lst_dg = nb % 10;
	if (nb <= 1)
		return (0);
	if (nb != 5 && lst_dg == 5)
		return (0);
	if (nb > 2 && nb % 2 == 0)
		return (0);
	i = 3;
	while (i < nb / 2)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb % 2 == 0 && nb != 2)
		nb++;
	while (nb <= 2147483647)
	{
		if (ft_is_prime(nb))
			break ;
		nb++;
	}
	return (nb);
}
