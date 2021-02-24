/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 17:52:04 by apanthap          #+#    #+#             */
/*   Updated: 2020/12/09 17:52:08 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_strlen(char *str)
{
	if (*str == '\0')
		return (0);
	else
		return (1 + ft_strlen(++str));
}

char	*ft_strdup(char *src)
{
	char *cpy;
	char *start;

	cpy = (char*)malloc((ft_strlen(src) + 1) * sizeof(char));
	if(!cpy)
		return ((char*)NULL);
	start = cpy;
	while(*src)
	{
		*cpy = *src;
		cpy++;
		src++;
	}
	cpy = 0;
	return (start);
}
