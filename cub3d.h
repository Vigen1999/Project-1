/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:00:19 by vasatrya          #+#    #+#             */
/*   Updated: 2021/05/19 12:00:24 by vasatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "Libft/libft.h"
# include "GNL/get_next_line.h"
# include "mlx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define SCL 0.5
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define M_SP 0.08
# define R_SP 0.03

typedef struct		s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct		s_key
{
	int				w;
	int				s;
	int				a;
	int				d;
	int				left;
	int				right;
	int				close;
}					t_key;

typedef struct		s_path
{
	char			*n_path;
	char			*w_path;
	char			*s_path;
	char			*e_path;
	char			*sp_path;
}					t_path;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct		s_map_3d {
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				mapx;
	int				mapy;
	double			delta_dist_x;
	double			delta_dist_Y;
	double			perp_wall_dist;
}					t_map_3d;

typedef struct		s_sprite {
	int				coll_sprite;
	double			sprite_x;
	double			sprite_y;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	int				sprite_screen_x;
	int				sprite_height;
	int				draw_start_y;
	int				draw_end_y;
	int				sprite_width;
	int				draw_start_x;
	int				draw_end_x;
	int				tex_x;
	int				tex_y;
	int				d;
	int				color;
}					t_sprite;

typedef struct		s_map {
	char			**map;
	double			p_x;
	double			p_y;
	int				map_x;
	int				map_y;
	int				s_h;
	int				s_w;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	int				side;
	int				step_x;
	int				step_y;
	int				tex_x;
	int				tex_y;
	double			step;
	double			tex_pos;
	double			side_dist_x;
	double			side_dist_y;
}					t_map;

typedef struct		s_cub {
	void			*mlx;
	void			*win;
	t_data			t_n;
	t_data			t_s;
	t_data			t_w;
	t_data			t_e;
	t_data			t_sp;
	t_data			data;
	t_sprite		sprite;
	t_map			map;
	t_map_3d		map_3d;
	t_rgb			rgb;
	int				sky_rgb;
	int				ground_rgb;
	int				pl;
	float			*x;
	float			*y;
	float			*dist;
	double			*close_sprite;
}					t_cub;

void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
unsigned	int		my_mlx_get_pixel(t_data *data, int x, int y);
int					my_mlx_create_rgb(int r, int g, int b);
int					my_mlx_close_win(t_cub *cub);
void				error(char *str, t_cub *cub);
void				malloc_arrays(t_cub *cub);
void				read_map(t_cub *cub, t_path *path, char *line);
void				error_check(t_cub *cub);
void				ft_map_3d(t_cub *cub);
void				ft_mini_map(t_cub *cub);
void				get_sprite(t_cub *cub, t_path *path);
int					sprites_count(t_cub *cub);
void				where_is_sprite(t_cub *cub);
void				sort_sprite(t_cub *cub);
void				print_sprite(t_cub *cub);
void				screen_shot(t_cub *cub);

#endif
