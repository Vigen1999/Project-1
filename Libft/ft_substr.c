/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 12:17:56 by vasatrya          #+#    #+#             */
/*   Updated: 2021/01/22 12:55:53 by vasatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char			*sub;
	unsigned int	size;
	int				i;

	i = 0;
	size = ft_strlen(s);
	if (!(sub = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start >= size)
		return (sub);
	while (i < len && s != '\0')
	{
		sub[i] = s[start++];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
