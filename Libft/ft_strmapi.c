/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:28:27 by vasatrya          #+#    #+#             */
/*   Updated: 2021/01/25 11:28:29 by vasatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mall;
	int		num;

	num = 0;
	if (!(mall = malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[num] != '\0')
	{
		mall[num] = (*f)(num, s[num]);
		num++;
	}
	mall[num] = '\0';
	return (mall);
}
