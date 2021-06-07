/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:20:52 by vasatrya          #+#    #+#             */
/*   Updated: 2021/01/25 15:28:10 by vasatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_atoi(const char *str);
void			ft_bzero(void *ptr, int n);
void			*ft_calloc(int nitems, int size);
int				ft_isalnum(int arg);
int				ft_isalpha(int arg);
int				ft_isascii(int arg);
int				ft_isdigit(int arg);
int				ft_isspace(int arg);
int				ft_isprint(int arg);
void			*ft_memccpy(void *dest, const void *src, int c, int n);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *str1, const void *str2, int n);
void			*ft_memcpy(void *dest, const void *src, int n);
void			*ft_memmove(void *str1, const void *str2, int n);
void			*ft_memset(void *ptr, int c, int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *str, int c);
char			*ft_strdup(char *src);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strlcat(char *dst, const char *src, int size);
int				ft_strlcpy(char *dst, const char *src, int size);
int				ft_strlen(const char *str);
int				ft_strncmp(const char *str1, const char *str2, int n);
char			*ft_strnstr(const char *str, const char *pattern, size_t len);
char			*ft_strrchr(const char *str, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, int len);
int				ft_toupper(int arg);
int				ft_tolower(int arg);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
				void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
#endif
