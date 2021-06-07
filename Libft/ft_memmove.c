/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:32:02 by vasatrya          #+#    #+#             */
/*   Updated: 2021/01/21 15:38:17 by vasatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, int n)
{
	char		*dest1;
	char		str[n];

	dest1 = dest;
	if (dest1 == NULL && src == NULL)
		return (NULL);
	ft_memcpy(str, src, n);
	ft_memcpy(dest1, str, n);
	return (dest);
}
