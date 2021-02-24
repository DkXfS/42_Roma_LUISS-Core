/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:36:52 by apanthap          #+#    #+#             */
/*   Updated: 2020/12/03 11:42:48 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		identificator(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (2);
	else if (c >= 'A' && c <= 'Z')
		return (3);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		char_id;
	int		word_length;
	char	*temp;

	temp = str;
	word_length = 0;
	while (*str != 0)
	{
		char_id = identificator(*str);
		if (char_id == 1 || char_id == 2 || char_id == 3)
		{
			word_length++;
			if (word_length == 1)
			{
				if (char_id == 2)
					*str -= 32;
			}
			else if (char_id == 3)
				*str += 32;
		}
		else
			word_length = 0;
		str++;
	}
	return (temp);
}
