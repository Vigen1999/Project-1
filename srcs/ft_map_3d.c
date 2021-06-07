/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:01:34 by vasatrya          #+#    #+#             */
/*   Updated: 2021/05/19 12:01:36 by vasatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	attach_texture(t_cub *cub, int x, int y)
{
	cub->map.tex_y = (int)cub->map.tex_pos & (TEXHEIGHT - 1);
	cub->map.tex_pos += cub->map.step;
	if (cub->map.side == 0)
	{
		if (cub->map.step_x > 0)
			my_mlx_pixel_put(&cub->data, x, y,
				my_mlx_get_pixel(&cub->t_s, cub->map.tex_x, cub->map.tex_y));
		else
			my_mlx_pixel_put(&cub->data, x, y,
				my_mlx_get_pixel(&cub->t_n, cub->map.tex_x, cub->map.tex_y));
	}
	else
	{
		if (cub->map.step_y > 0)
			my_mlx_pixel_put(&cub->data, x, y,
				my_mlx_get_pixel(&cub->t_e, cub->map.tex_x, cub->map.tex_y));
		else
			my_mlx_pixel_put(&cub->data, x, y,
				my_mlx_get_pixel(&cub->t_w, cub->map.tex_x, cub->map.tex_y));
	}
}

void	ft_map_3d(t_cub *cub)
{
	int x;

	cub->data.img = mlx_new_image(cub->mlx, cub->map.s_w, cub->map.s_h);
	cub->data.addr = mlx_get_data_addr(cub->data.img, &cub->data.bits_per_pixel,
										&cub->data.line_length, &cub->data.endian);
	x = 0;
	while (x < cub->map.s_w)
	{
		cub->map_3d.camera_x = 2 * x / (double)cub->map.s_w - 1;
		cub->map_3d.ray_dir_x = cub->map.dir_x + cub->map.plane_x * cub->map_3d.camera_x;
		cub->map_3d.ray_dir_y = cub->map.dir_y + cub->map.plane_y * cub->map_3d.camera_x;
		cub->map_3d.mapx = (int)cub->map.p_x;
		cub->map_3d.mapy = (int)cub->map.p_y;
		
		int hit = 0;
		if (cub->map_3d.ray_dir_y == 0)
			cub->map_3d.delta_dist_x = 0;
		else
			if (cub->map_3d.ray_dir_x == 0) 
				cub->map_3d.delta_dist_x = 1;
			else
				cub->map_3d.delta_dist_x = fabs(1 / cub->map_3d.ray_dir_x);
		if (cub->map_3d.ray_dir_x == 0)
      		cub->map_3d.delta_dist_Y = 0;
		else
			if (cub->map_3d.ray_dir_y == 0) 
				cub->map_3d.delta_dist_Y = 1; 
			else
				cub->map_3d.delta_dist_Y = fabs(1 / cub->map_3d.ray_dir_y);
		if (cub->map_3d.ray_dir_x < 0)
		{
			cub->map.step_x = -1;
			cub->map.side_dist_x = (cub->map.p_x - cub->map_3d.mapx) * cub->map_3d.delta_dist_x;
		}
		else
		{
			cub->map.step_x = 1;
			cub->map.side_dist_x = (cub->map_3d.mapx + 1.0 - cub->map.p_x) * cub->map_3d.delta_dist_x;
		}
		if (cub->map_3d.ray_dir_y < 0)
		{
			cub->map.step_y = -1;
			cub->map.side_dist_y = (cub->map.p_y - cub->map_3d.mapy) * cub->map_3d.delta_dist_Y;
		}
		else
		{
			cub->map.step_y = 1;
			cub->map.side_dist_y = (cub->map_3d.mapy + 1.0 - cub->map.p_y) * cub->map_3d.delta_dist_Y;
		}
		while (hit == 0)
		{
			if (cub->map.side_dist_x < cub->map.side_dist_y)
			{
				cub->map.side_dist_x += cub->map_3d.delta_dist_x;
				cub->map_3d.mapx += cub->map.step_x;
				cub->map.side = 0;
			}
			else
			{
				cub->map.side_dist_y += cub->map_3d.delta_dist_Y;
				cub->map_3d.mapy += cub->map.step_y;
				cub->map.side = 1;
			}
			if (cub->map.map[cub->map_3d.mapx][cub->map_3d.mapy] == '1')
				hit = 1;
		}
		
		if (cub->map.side == 0)
			cub->map_3d.perp_wall_dist = (cub->map_3d.mapx - cub->map.p_x + (1 - cub->map.step_x) / 2) / cub->map_3d.ray_dir_x;
     	else
			cub->map_3d.perp_wall_dist = (cub->map_3d.mapy - cub->map.p_y + (1 - cub->map.step_y) / 2) / cub->map_3d.ray_dir_y; 
		
		cub->close_sprite[x] = cub->map_3d.perp_wall_dist;
		int line_height = (int)(cub->map.s_h / cub->map_3d.perp_wall_dist);
		int sky = -line_height / 2 + cub->map.s_h / 2;
		if (sky < 0)
			sky = 0;

		int ground = line_height / 2 + cub->map.s_h / 2;
		if (ground >= cub->map.s_h)
			ground = cub->map.s_h - 1;

		double wall_x;
		if (cub->map.side == 0)
			wall_x = cub->map.p_y + cub->map_3d.perp_wall_dist * cub->map_3d.ray_dir_y;
		else
			wall_x = cub->map.p_x + cub->map_3d.perp_wall_dist * cub->map_3d.ray_dir_x;
		wall_x -= floor((wall_x));
		cub->map.tex_x = (int)(wall_x * (double)TEXWIDTH);
		if (cub->map.side == 0 && cub->map_3d.ray_dir_x > 0)
			cub->map.tex_x = TEXWIDTH - cub->map.tex_x - 1;
		if (cub->map.side == 1 && cub->map_3d.ray_dir_y < 0)
			cub->map.tex_x = TEXWIDTH - cub->map.tex_x - 1;
		cub->map.step = 1.0 * TEXHEIGHT / line_height;
		cub->map.tex_pos = (sky - cub->map.s_h / 2
							+ line_height / 2) * cub->map.step;
	
		int y;

		y = 0;
		while (y < cub->map.s_h)
		{
			if (y < sky)
				my_mlx_pixel_put(&cub->data, x, y, cub->sky_rgb);
			if (y >= sky && y <= ground)
				attach_texture(cub, x, y);
			if (y > ground && y < cub->map.s_h)
				my_mlx_pixel_put(&cub->data, x, y, cub->ground_rgb);
			y++;
		}
		x++;
	}
	sort_sprite(cub);
	print_sprite(cub);
	ft_mini_map(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->data.img, 0, 0);
}
