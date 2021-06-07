/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:57:20 by vasatrya          #+#    #+#             */
/*   Updated: 2021/02/06 16:57:24 by vasatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*till_next(char *str)
{
	int		size;
	int		i;
	char	*st;

	size = 0;
	i = 0;
	while (str[size] != '\n' && str[size])
		size++;
	st = malloc(size + 1);
	while (str[i] != '\n' && str[i])
	{
		st[i] = str[i];
		i++;
	}
	st[i] = '\0';
	return (st);
}

char	*rest(char *str)
{
	int		i;
	int		j;
	char	*st;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	st = malloc(ft_strlen_gnl(str) - i + 1);
	i++;
	while (str[i] != '\0' && str[i])
		st[j++] = str[i++];
	st[j] = '\0';
	free(str);
	return (st);
}

int		get_next_line(int fd, char **line)
{
	char		*buff;
	int			is_read;
	static char *rem;

	is_read = 1;
	if (fd < 0 || !line || 1000 <= 0 ||
	!(buff = malloc(1000 + 1)))
		return (-1);
	while (!ft_strchr(rem, '\n') && is_read != 0)
	{
		if ((is_read = read(fd, buff, 1000)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[is_read] = '\0';
		rem = ft_strjoin_gnl(rem, buff);
	}
	free(buff);
	*line = till_next(rem);
	rem = rest(rem);
	if (is_read == 0)
		return (0);
	return (1);
}
