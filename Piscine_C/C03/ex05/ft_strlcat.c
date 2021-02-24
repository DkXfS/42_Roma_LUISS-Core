/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 12:47:49 by apanthap          #+#    #+#             */
/*   Updated: 2020/12/06 13:28:37 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int count;

	count = 0;
	while (*str != 0)
	{
		str++;
		count++;
	}
	return (count);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int dest_len;
	unsigned int src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (src_len + dest_len);
	while (*dest != 0)
	{
		dest++;
		size--;
	}
	while (size != 0 && (size - 1) > 0 && *src != 0)
	{
		*dest = *src;
		dest++;
		src++;
		size--;
	}
	if (size >= 1)
		*dest = 0;
	return (src_len + dest_len);
}
