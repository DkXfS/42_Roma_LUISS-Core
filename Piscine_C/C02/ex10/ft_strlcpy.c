/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:34:20 by apanthap          #+#    #+#             */
/*   Updated: 2020/12/03 11:38:21 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int length;

	length = 0;
	while (*src != 0 && size != 0 && (size - 1) > 0)
	{
		*dest = *src;
		dest++;
		src++;
		length++;
		size--;
	}
	while (*src != 0)
	{
		length++;
		src++;
	}
	if (size >= 1)
		*dest = '\0';
	return (length);
}
