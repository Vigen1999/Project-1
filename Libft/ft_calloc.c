/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:47:32 by vasatrya          #+#    #+#             */
/*   Updated: 2021/01/21 17:04:37 by vasatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int nitems, int size)
{
	int		i;
	char	*mall;

	i = 0;
	if (!(mall = malloc(nitems * size)))
		return (NULL);
	while (i < nitems * size)
	{
		mall[i] = 0;
		i++;
	}
	return (mall);
}
