/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:07:19 by apanthap          #+#    #+#             */
/*   Updated: 2021/01/20 16:15:17 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		buff_str(char **buff, char **str)
{
	int		found;
	size_t	i;

	found = 0;
	i = 0;
	if (*buff)
	{
		while (i < ft_strlen(*buff) && !found)
		{
			if ((*buff)[i++] == '\n')
			{
				ft_substr(str, *buff, 0, i - 1);
				ft_substr(buff, *buff, i, ft_strlen(*buff) - i + 1);
				found = 1;
			}
		}
		if (!found)
		{
			ft_substr(str, *buff, 0, ft_strlen(*buff));
			free(*buff);
			*buff = NULL;
		}
	}
	return (found);
}

int		read_loop(char **line, char **buff, int fd, char *str)
{
	int		found;
	size_t	count;
	size_t	i;

	found = 0;
	while (!found)
	{
		if ((i = read(fd, (void*)str, BUFFER_SIZE)) < 1)
			break ;
		count = 0;
		while (count < i && !found)
		{
			if (str[count++] == '\n')
			{
				ft_substr(buff, str, count, i - count);
				*line = strconcat(*line, str, count - 1);
				found = 1;
			}
		}
		if (!found)
			*line = strconcat(*line, str, i);
	}
	return (i);
}

int		get_next_line(int fd, char **line)
{
	static char	*str_lst[256];
	ssize_t		i;
	int			found;
	char		*str;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 255 || !line || read(fd, 0, 0) < 0)
		return (-1);
	if (!(str = (char*)malloc(BUFFER_SIZE)))
		return (-1);
	i = 0;
	if (!(*line = (char*)malloc(1)))
		i = -1;
	else
		**line = 0;
	found = 0;
	if (i != -1 && (i = buff_str(&str_lst[fd], line)))
		found = 1;
	if (i != -1 && !found)
		if ((i = read_loop(line, &str_lst[fd], fd, str)) == -1)
			free(str_lst[fd]);
	free(str);
	if (i > 0)
		return (1);
	return (i);
}
