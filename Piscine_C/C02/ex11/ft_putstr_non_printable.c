/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:32:40 by apanthap          #+#    #+#             */
/*   Updated: 2020/12/03 11:37:54 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(unsigned char elem)
{
	char c1;
	char c2;

	c1 = "0123456789abcdef"[elem / 16];
	c2 = "0123456789abcdef"[elem % 16];
	write(1, &c1, 1);
	write(1, &c2, 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != 0)
	{
		if (*str < 32 || *str > 126)
		{
			write(1, "\\", 1);
			print_hex(*str);
		}
		else
			write(1, str, 1);
		str++;
	}
}
