/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:27:02 by apanthap          #+#    #+#             */
/*   Updated: 2020/11/28 17:27:05 by apanthap         ###   ########.fr       */
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
			ft_putchar('B');
	}
}

void	par_prin2(int a, int x)
{
	if (a == 0 || a == x-1)
		ft_putchar('B');
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
				par_prin(a, x, 'A', 'C');
			else
			{
				if (b == y-1)
					par_prin(a, x, 'C', 'A');
				else
					par_prin2(a, x);
			}
			a++;
		}
		ft_putchar('\n');
		b++;
	}
}
