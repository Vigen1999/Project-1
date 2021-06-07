/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:33:13 by vasatrya          #+#    #+#             */
/*   Updated: 2021/01/20 14:54:41 by vasatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, int n)
{
	int					i;
	int					value;
	unsigned const char	*src1;
	unsigned const char	*src2;

	i = 0;
	src1 = str1;
	src2 = str2;
	value = 0;
	while (i < n)
	{
		if (src1[i] != src2[i])
		{
			value += (unsigned const char)src1[i]
			- (unsigned const char)src2[i];
			return (value);
		}
		i++;
	}
	return (0);
}
