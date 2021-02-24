/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 10:20:02 by apanthap          #+#    #+#             */
/*   Updated: 2020/12/06 12:47:29 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char *bookmark;
	char *n_start;

	n_start = to_find;
	if (*to_find == 0)
		return (str);
	bookmark = 0;
	while (*str && *to_find)
	{
		if (*str == *to_find && *(str + 1) == *(to_find + 1))
		{
			if (bookmark == 0)
				bookmark = str;
			to_find++;
		}
		else
		{
			bookmark = 0;
			to_find = n_start;
		}
		str++;
	}
	return (bookmark);
}
