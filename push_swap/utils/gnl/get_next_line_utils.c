/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:11:39 by apanthap          #+#    #+#             */
/*   Updated: 2021/01/20 16:11:41 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	if (s)
		while (*s)
		{
			len++;
			s++;
		}
	return (len);
}

char	*strconcat(char *s1, char *s2, ssize_t len)
{
	size_t	totlen;
	char	*str;
	int		i;
	int		j;
	int		lens1;

	lens1 = ft_strlen(s1);
	i = 0;
	j = 0;
	totlen = lens1 + len;
	str = (char*)malloc(totlen + 1);
	if (s1)
	{
		while (i < lens1)
		{
			str[i] = s1[i];
			i++;
		}
		free(s1);
	}
	while (j < len)
		str[i++] = s2[j++];
	str[i] = 0;
	return (str);
}

void	ft_substr(char **ret, char const *s, unsigned int start, size_t len)
{
	char *new_str;
	char *str_start;

	if (!(new_str = (char*)malloc(len + 1)))
	{
		free(*ret);
		*ret = new_str;
	}
	str_start = new_str;
	while (start)
	{
		s++;
		start--;
	}
	new_str[len] = 0;
	while (len)
	{
		*new_str = *s;
		new_str++;
		s++;
		len--;
	}
	free(*ret);
	*ret = str_start;
}
