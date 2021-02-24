/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:50:59 by apanthap          #+#    #+#             */
/*   Updated: 2020/11/28 16:52:09 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	printer(int a, int x, char c1, char c2)
{
	if (a == 0 || a == x-1)
		ft_putchar(c1);
	else
		ft_putchar(c2);
}

void	rush(int x, int y)
{
	int a;
	int b;

	b = 0;
	while (b < y && x > 0)
	{
		a = 0;
		while (a < x-1)
		{
			if (b == 0)
				printer(a, x, 'A', 'B');
			else
			{
				if (b == y-1)
					printer(a, x, 'C', 'B');
				else
					printer(a, x, 'B', ' ');
			}
			a++;
		}
		ft_putchar('\n');
		b++;
	}
}
