/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:14:51 by vasatrya          #+#    #+#             */
/*   Updated: 2021/01/22 17:14:54 by vasatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_count(char const *s, char c)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int		word_len(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static void		*free_mall(char **splitted, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	return (NULL);
}

static char		**word(char const *s, int words, char c, char **mall)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	while (++i < words)
	{
		while (*s == c)
			s++;
		len = word_len(s, c);
		if (!(mall[i] = (char *)malloc(sizeof(char) * (len + 1))))
			return (free_mall(mall, i));
		j = 0;
		while (j < len)
			mall[i][j++] = *s++;
		mall[i][j] = '\0';
	}
	mall[i] = NULL;
	return (mall);
}

char			**ft_split(char	const *s, char c)
{
	char	**mall;
	int		words;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	if (!(mall = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	mall = word(s, words, c, mall);
	return (mall);
}
