/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:35:50 by vasatrya          #+#    #+#             */
/*   Updated: 2021/01/22 13:35:52 by vasatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*mall;
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && s1[start])
		++start;
	while (start < end && ft_strchr(set, s1[end]) && s1[end])
		--end;
	if (!(mall = (char *)malloc((end - start) + 2)))
		return (0);
	ft_strlcpy(mall, s1 + start, end - start + 2);
	return (mall);
}
