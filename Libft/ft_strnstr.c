/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:14:17 by vasatrya          #+#    #+#             */
/*   Updated: 2021/01/20 17:10:12 by vasatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t len1;

	if (*s2 == '\0')
		return ((char *)s1);
	len1 = ft_strlen(s2);
	while (*s1 && len >= len1)
	{
		if (*s1 == *s2 && ft_strncmp(s1, s2, len1) == 0)
			return ((char *)s1);
		s1++;
		len--;
	}
	return (NULL);
}
