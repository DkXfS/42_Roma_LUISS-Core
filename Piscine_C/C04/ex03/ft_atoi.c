/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 10:14:08 by apanthap          #+#    #+#             */
/*   Updated: 2020/12/07 10:24:30 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	char_id(char c)
{
	if (c == 32 || (c > 8 && c < 14))
		return (0);
	if (c == '-' || c == '+')
		return (1);
	if (c >= '0' && c <= '9')
		return (2);
	else
		return (3);
}

int	num_build(int n, char c)
{
	n *= 10;
	n += c - '0';
	return (n);
}

int	ft_atoi(char *str)
{
	int	flg;
	int	minus_count;
	int	num;

	flg = 0;
	num = 0;
	minus_count = 0;
	while (*str && flg < 3 && char_id(*str) < 3)
	{
		if (char_id(*str) >= flg)
		{
			flg = char_id(*str);
			if (flg == 1 && *str == '-')
				minus_count++;
			if (flg == 2)
				num = num_build(num, *str);
		}
		else
			flg = 3;
		str++;
	}
	if (minus_count % 2)
		num *= -1;
	return (num);
}
