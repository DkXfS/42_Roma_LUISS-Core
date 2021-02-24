/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:04:00 by apanthap          #+#    #+#             */
/*   Updated: 2020/11/28 16:04:03 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	printer(int x, int y, int a, int b)
{
	if (b == 0 || b == y-1)
	{
		if (a == 0 || a == x-1)
			ft_putchar('o');
		else
			ft_putchar('-');
	}
	else
	{
		if (a == 0 || a == x-1)
			ft_putchar('|');
		else
			ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int a;
	int b;

	b = 0;
	while (b < y && x > 0)
	{
		a = 0;
		while (a < x)
		{
			printer(x, y, a, b);
			a++;
		}
		ft_putchar('\n');
		b++;
	}
}
