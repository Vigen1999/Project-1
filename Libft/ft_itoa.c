/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:24:46 by vasatrya          #+#    #+#             */
/*   Updated: 2021/01/23 17:24:49 by vasatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int nb)
{
	int count;

	count = 0;
	if (nb <= 0)
		nb *= -1;
	while (nb > 0)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

static int	pow(int a)
{
	int c;

	c = 1;
	while (a > 1)
	{
		c *= 10;
		a--;
	}
	return (c);
}

static int	outof(int n)
{
	if (n == -2147483648)
		return (0);
	return (1);
}

char		*ft_itoa(int n)
{
	char	*st;
	int		i;
	int		l;
	int		c;

	i = 0;
	if (!(c = outof(n)))
		n++;
	l = ft_count(n) + 1;
	if (!(st = (char *)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	if (n == 0)
		st[i++] = '0';
	if (n < 0)
	{
		n *= -1;
		st[i++] = '-';
	}
	while (l-- > 1)
		st[i++] = ((n / (pow(l))) % 10) + '0';
	if (c == 0)
		st[i - 1] = '8';
	st[i] = '\0';
	return (st);
}
