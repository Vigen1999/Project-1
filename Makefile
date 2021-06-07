SRCS	= cub3d.c	./GNL/get_next_line.c \
					./GNL/get_next_line_utils.c \
					./Libft/ft_atoi.c \
					./Libft/ft_isdigit.c \
					./Libft/ft_strjoin.c \
					./Libft/ft_strlen.c \
					./Libft/ft_isspace.c \
					./srcs/mini_map.c \
					./srcs/ft_sprite.c \
					./srcs/screen_shot.c \
					./srcs/my_mlx.c \
					./srcs/read_map.c \
					./srcs/ft_map_3d.c \
					./srcs/error_check.c
OBJS	= $(SRCS:.c=.o)

RM		= rm -f

CC		= cc

NAME	= cub3D

LIBS	= -Lmlx -lmlx -framework OpenGL -framework AppKit -lm

CFLAGS	= -O3 -I. -Wall -Wextra -Werror

.c.o:
			$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
				gcc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

clean:
			$(RM) $(OBJS) 

fclean:			clean
			$(RM) $(NAME)
			
re:			fclean all

bonus:		$(OBJS) 
			ar rcs $(NAME) $(OBJS) 

.PHONY:		$(NAME) all clean re fclean