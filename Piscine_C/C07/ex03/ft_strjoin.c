/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:07:11 by apanthap          #+#    #+#             */
/*   Updated: 2020/12/10 11:25:17 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	if (*str == '\0')
		return (0);
	else
		return (1 + ft_strlen(++str));
}

void	make_str(char *res, char **strs, char *sep, int size)
{
	char *substr;
	char *sep_start;

	sep_start = sep;
	while (size)
	{
		substr = *strs;
		while (*substr)
		{
			*res = *substr;
			res++;
			substr++;
		}
		size--;
		sep = sep_start;
		if (size)
			while (*sep)
			{
				*res = *sep;
				res++;
				sep++;
			}
		strs++;
	}
	*res = 0;
}

char	*return_null()
{
	char *result;

	result = (char*)malloc(sizeof(char));
	if (result)
		*result = 0;
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	char	**strs_cp;
	int		tot_len;
	int		size_cp;

	size_cp = size;
	strs_cp = strs;
	if (size == 0)
		return return_null();
	tot_len = 0;
	while (size)
	{
		tot_len += ft_strlen(*strs);
		strs++;
		size--;
	}
	tot_len = tot_len + (size_cp - 1) * ft_strlen(sep);
	result = (char*)malloc((tot_len + 1) * sizeof(char));
	if (!result)
		return (result);
	make_str(result, strs_cp, sep, size_cp);
	return (result);
}