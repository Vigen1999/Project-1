/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:59:40 by vasatrya          #+#    #+#             */
/*   Updated: 2021/01/21 13:01:17 by vasatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tolower(int arg)
{
	if (arg >= 'A' && arg <= 'Z')
	{
		arg += 32;
		return (arg);
	}
	return (arg);
}
