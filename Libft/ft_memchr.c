/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:34:35 by vasatrya          #+#    #+#             */
/*   Updated: 2021/01/20 15:07:04 by vasatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;

	src = s;
	while (n)
	{
		if (*src == (unsigned char)c)
			return ((unsigned char*)src);
		src++;
		n--;
	}
	return (NULL);
}
