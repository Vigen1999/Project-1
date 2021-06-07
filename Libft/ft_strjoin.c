/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 12:58:02 by vasatrya          #+#    #+#             */
/*   Updated: 2021/01/22 12:58:05 by vasatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l1;
	int		l2;
	int		i;
	int		j;
	char	*s3;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (!(s3 = (char *)malloc(sizeof(char) * (l1 + l2 + 1))))
		return (NULL);
	i = 0;
	while (i < l1)
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < l2)
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}
