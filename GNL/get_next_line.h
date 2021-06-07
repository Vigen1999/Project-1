/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:57:20 by vasatrya          #+#    #+#             */
/*   Updated: 2021/02/06 16:57:24 by vasatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

int				ft_strlen_gnl(const char *str);
int				ft_strlcpy_gnl(char *dst, const char *src, int size);
char			*ft_strjoin_gnl(char *s1, char *s2);
char			*ft_strchr(const char *str, int c);
int				get_next_line(int fd, char **line);
#endif
