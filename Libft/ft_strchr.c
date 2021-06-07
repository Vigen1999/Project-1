/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:58:44 by vasatrya          #+#    #+#             */
/*   Updated: 2021/01/20 16:04:08 by vasatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	const char *ptr;

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
