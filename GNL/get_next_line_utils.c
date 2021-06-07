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

int		ft_strlen_gnl(const char *str)
{
	int size;

	size = 0;
	if (str == NULL)
		return (0);
	while (str[size])
		size++;
	return (size);
}

int		ft_strlcpy_gnl(char *dst, const char *src, int size)
{
	int	i;

	i = 0;
	if (size == 0)
		return (ft_strlen_gnl(src));
	while ((i < size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen_gnl(src));
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		l1;
	int		l2;
	char	*s3;

	l1 = ft_strlen_gnl(s1);
	l2 = ft_strlen_gnl(s2);
	if (!(s3 = (char *)malloc(l1 + l2 + 1)))
		return (0);
	ft_strlcpy_gnl(s3, s1, l1 + 1);
	ft_strlcpy_gnl(s3 + l1, s2, l2 + 1);
	if (s1 != NULL)
		free(s1);
	return (s3);
}

char	*ft_strchr(const char *str, int c)
{
	const char *ptr;

	if (!str)
		return (0);
	while (*str != '\0')
	{
		if (*str == (unsigned char)c)
		{
			ptr = str;
			return ((char *)ptr);
		}
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}
