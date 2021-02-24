/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:11:48 by apanthap          #+#    #+#             */
/*   Updated: 2021/01/20 16:11:51 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*strconcat(char *s1, char *s2, ssize_t len);
size_t	ft_strlen(const char *s);
int		buff_str(char **buff, char **str);
int		get_next_line(int fd, char **line);
void	ft_substr(char **ret, char const *s, unsigned int start, size_t len);
int		read_loop(char **line, char **buff, int fd, char *str);

#endif
