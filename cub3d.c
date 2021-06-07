/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:59:59 by vasatrya          #+#    #+#             */
/*   Updated: 2021/05/19 12:00:06 by vasatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_key			key;

static int		button_pre(int keycode)
{
	if (keycode == 13)
		key.w = 1;
	if (keycode == 1)
		key.s = 1;
	if (keycode == 0)
		key.a = 1;
	if (keycode == 2)
		key.d = 1;
	if (keycode == 123)
		key.left = 1;
	if (keycode == 124)
		key.right = 1;
	if (keycode == 53)
		key.close = 1;
	return (0);
}

static int		button_re(int keycode)
{
	if (keycode == 13)
		key.w = 0;
	if (keycode == 1)
		key.s = 0;
	if (keycode == 0)
		key.a = 0;
	if (keycode == 2)
		key.d = 0;
	if (keycode == 123)
		key.left = 0;
	if (keycode == 124)
		key.right = 0;
	if (keycode == 53)
		key.close = 0;
	return (0);
}

static int		key_hook(t_cub *cub)
{
	double old_dir_x;
	double old_plane_x;
	double xo;
	double yo;

	if (cub->map.dir_x < 0)
		xo = -SCL;
	else
		xo = SCL;
	if (cub->map.dir_y < 0)
		yo = -SCL;
	else
		yo = SCL;
	if (key.w == 1)
	{
		if (cub->map.map[(int)(cub->map.p_x + xo + cub->map.dir_x * M_SP)]
					[(int)(cub->map.p_y + cub->map.dir_y * M_SP)] == '0')
			cub->map.p_x += cub->map.dir_x * M_SP;
		if (cub->map.map[(int)(cub->map.p_x + cub->map.dir_x * M_SP)]
					[(int)(cub->map.p_y + yo + cub->map.dir_y * M_SP)] == '0')
			cub->map.p_y += cub->map.dir_y * M_SP;
	}
	if (key.s == 1)
	{
		if (cub->map.map[(int)(cub->map.p_x - xo - cub->map.dir_x * M_SP)]
					[(int)(cub->map.p_y - cub->map.dir_y * M_SP)] == '0')
			cub->map.p_x -= cub->map.dir_x * M_SP;
		if (cub->map.map[(int)(cub->map.p_x - cub->map.dir_x * M_SP)]
					[(int)(cub->map.p_y - yo - cub->map.dir_y * M_SP)] == '0')
			cub->map.p_y -= cub->map.dir_y * M_SP;
	}
	if (key.a == 1)
	{
		if (cub->map.map[(int)(cub->map.p_x + cub->map.dir_x * M_SP)]
					[(int)(cub->map.p_y + xo - cub->map.dir_y * M_SP)] == '0')
			cub->map.p_y += cub->map.dir_x * M_SP;
		if (cub->map.map[(int)(cub->map.p_x - yo + cub->map.dir_x * M_SP)]
					[(int)(cub->map.p_y + cub->map.dir_y * M_SP)] == '0')
			cub->map.p_x -= cub->map.dir_y * M_SP;
	}
	if (key.d == 1)
	{
		if (cub->map.map[(int)(cub->map.p_x + cub->map.dir_x * M_SP)]
					[(int)(cub->map.p_y - xo + cub->map.dir_y * M_SP)] == '0')
			cub->map.p_y -= cub->map.dir_x * M_SP;
		if (cub->map.map[(int)(cub->map.p_x + yo - cub->map.dir_x * M_SP)]
					[(int)(cub->map.p_y + cub->map.dir_y * M_SP)] == '0')
			cub->map.p_x += cub->map.dir_y * M_SP;
	}
	if (key.left == 1)
	{
		old_dir_x = cub->map.dir_x;
		cub->map.dir_x = cub->map.dir_x * cos(R_SP)
						- cub->map.dir_y * sin(R_SP);
		cub->map.dir_y = old_dir_x * sin(R_SP)
						+ cub->map.dir_y * cos(R_SP);
		old_plane_x = cub->map.plane_x;
		cub->map.plane_x = cub->map.plane_x * cos(R_SP)
						- cub->map.plane_y * sin(R_SP);
		cub->map.plane_y = old_plane_x * sin(R_SP)
						+ cub->map.plane_y * cos(R_SP);
	}
	if (key.right == 1)
	{
		old_dir_x = cub->map.dir_x;
		cub->map.dir_x = cub->map.dir_x * cos(-R_SP)
						- cub->map.dir_y * sin(-R_SP);
		cub->map.dir_y = old_dir_x * sin(-R_SP)
						+ cub->map.dir_y * cos(-R_SP);
		old_plane_x = cub->map.plane_x;
		cub->map.plane_x = cub->map.plane_x * cos(-R_SP)
						- cub->map.plane_y * sin(-R_SP);
		cub->map.plane_y = old_plane_x * sin(-R_SP)
						+ cub->map.plane_y * cos(-R_SP);
	}
	if (key.close == 1)
		my_mlx_close_win(cub);
	ft_map_3d(cub);
	return (0);
}

int				main(int argc, char *argv[])
{
	t_cub	cub;
	t_path	path;
	int		fd;
	int		is_true;
	char	*line;

	if (argc < 2)
		error("Error\nThe map is missing", &cub);
	fd = open(argv[1], O_RDONLY);
	cub.map.map = malloc(sizeof(char *) * 100);
	is_true = 1;
	while (is_true)
	{
		if (!get_next_line(fd, &line))
			is_true = 0;
		read_map(&cub, &path, line);
	}
	cub.map.map[cub.map.map_x] = NULL;
	error_check(&cub);
	cub.sprite.coll_sprite = sprites_count(&cub);
	malloc_arrays(&cub);
	where_is_sprite(&cub);
	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, cub.map.s_w,
								cub.map.s_h, "Wolfenstein Demo");
	get_sprite(&cub, &path);
	ft_map_3d(&cub);
	if (argc == 3)
		screen_shot(&cub);
	mlx_hook(cub.win, 2, (1L << 0), &button_pre, &cub);
	mlx_hook(cub.win, 3, (1L << 0), &button_re, &cub);
	mlx_loop_hook(cub.mlx, &key_hook, &cub);
	mlx_loop(cub.mlx);
}
