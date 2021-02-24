/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:25:54 by apanthap          #+#    #+#             */
/*   Updated: 2020/11/28 16:25:59 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	par_prin(int a, int x, char c1, char c2)
{
	if (a == 0)
		ft_putchar(c1);
	else
	{
		if (a == x-1)
			ft_putchar(c2);
		else
			ft_putchar('*');
	}
}

void	par_prin2(int a, int x)
{
	if (a == 0 || a == x-1)
		ft_putchar('*');
	else
		ft_putchar(' ');
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
			if (b == 0)
				par_prin(a, x, '/', '\\');
			else
			{
				if (b == y-1)
					par_prin(a, x, '\\', '/');
				else
					par_prin2(a, x);
			}
			a++;
		}
		ft_putchar('\n');
		b++;
	}
}
