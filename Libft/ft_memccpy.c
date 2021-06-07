/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:54:54 by vasatrya          #+#    #+#             */
/*   Updated: 2021/01/20 13:55:05 by vasatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, int n)
{
	unsigned char		*dest1;
	unsigned const char	*src1;
	int					i;

	dest1 = dest;
	src1 = src;
	i = 0;
	while (i < n)
	{
		if (src1[i] == (unsigned char)c)
		{
			dest1[i] = src1[i];
			return (&dest1[i + 1]);
		}
		dest1[i] = src1[i];
		i++;
	}
	return (NULL);
}
