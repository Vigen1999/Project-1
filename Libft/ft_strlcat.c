/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:22:42 by vasatrya          #+#    #+#             */
/*   Updated: 2021/01/21 14:23:48 by vasatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, int destsize)
{
	int	size;
	int	j;

	size = 0;
	j = 0;
	while (dst[size] && size < destsize)
		size++;
	while (src[j] && (size + j + 1) < destsize)
	{
		dst[size + j] = src[j];
		j++;
	}
	if (size < destsize)
		dst[size + j] = '\0';
	return (size + ft_strlen(src));
}
