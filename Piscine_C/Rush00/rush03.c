/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:07:31 by apanthap          #+#    #+#             */
/*   Updated: 2020/11/28 17:07:37 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	printer(int a, int x, int b, int y)
{
	if (b == 0 || b == y-1)
	{
		if (a == 0)
			ft_putchar('A');
		else
		{
			if (a == x-1)
				ft_putchar('C');
			else
				ft_putchar('B');
		}
	}
	else
	{
		if (a == 0 || a == x-1)
			ft_putchar('B');
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
			printer(a, x, b, y);
			a++;
		}
		ft_putchar('\n');
		b++;
	}
}
