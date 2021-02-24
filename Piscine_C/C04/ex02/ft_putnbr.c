/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:25:32 by apanthap          #+#    #+#             */
/*   Updated: 2020/12/07 09:27:31 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		prnt_ngtv(int num)
{
	write(1, "-", 1);
	return (-num);
}

void	ft_putnbr(int nb)
{
	int		num;
	int		mod_num;
	char	to_print;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nb < 0)
			nb = prnt_ngtv(nb);
		mod_num = 1;
		num = nb;
		while (num >= 10)
		{
			num = num / 10;
			mod_num = mod_num * 10;
		}
		while (mod_num > 0)
		{
			to_print = '0' + (nb / mod_num);
			nb = nb % mod_num;
			write(1, &to_print, 1);
			mod_num /= 10;
		}
	}
}
