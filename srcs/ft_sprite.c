/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:01:02 by vasatrya          #+#    #+#             */
/*   Updated: 2021/05/19 12:01:05 by vasatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	where_is_sprite(t_cub *cub)
{
	int i;
	int j;
	int coll;

	i = 0;
	coll = 0;
	while (cub->map.map[i] != NULL)
	{
		j = 0;
		while (cub->map.map[i][j] != '\0')
		{
			if (cub->map.map[i][j] == '2')
			{
				cub->x[coll] = i + 0.5;
				cub->y[coll] = j + 0.5;
				coll++;
			}
			++j;
		}
		++i;
	}
}

int				sprites_count(t_cub *cub)
{
	int i;
	int j;
	int coll;

	i = 0;
	coll = 0;
	while (cub->map.map[i] != NULL)
	{
		j = 0;
		while (cub->map.map[i][j] != '\0')
		{
			if (cub->map.map[i][j] == '2')
				coll++;
			++j;
		}
		++i;
	}
	return (coll);
}

static	void	reverse_sprite(t_cub *cub, int j)
{
	float tmp;

	tmp = cub->dist[j - 1];
	cub->dist[j - 1] = cub->dist[j];
	cub->dist[j] = tmp;
	tmp = cub->x[j - 1];
	cub->x[j - 1] = cub->x[j];
	cub->x[j] = tmp;
	tmp = cub->y[j - 1];
	cub->y[j - 1] = cub->y[j];
	cub->y[j] = tmp;
}

static	void	sort_distance(t_cub *cub)
{
	int i;
	int j;

	i = 1;
	while (i < cub->sprite.coll_sprite)
	{
		j = i;
		while ((int)cub->dist[j] > (int)cub->dist[j - 1] && j != 0)
		{
			reverse_sprite(cub, j);
			--j;
		}
		++i;
	}
}

void			sort_sprite(t_cub *cub)
{
	int i;

	i = -1;
	while (++i < cub->sprite.coll_sprite)
	{
		cub->dist[i] = ((cub->map.p_x - cub->x[i])
		* (cub->map.p_x - cub->x[i])
		+ (cub->map.p_y - cub->y[i]) * (cub->map.p_y - cub->y[i]));
	}
	if (cub->sprite.coll_sprite > 1)
		sort_distance(cub);
}

void	set_sprite(t_cub *cub, int i)
{
	cub->sprite.sprite_x = cub->x[i] - cub->map.p_x;
	cub->sprite.sprite_y = cub->y[i] - cub->map.p_y;
	cub->sprite.inv_det = 1.0 / (cub->map.plane_x * cub->map.dir_y
					- cub->map.dir_x * cub->map.plane_y);
	cub->sprite.transform_x = cub->sprite.inv_det * (cub->map.dir_y * cub->sprite.sprite_x
								- cub->map.dir_x * cub->sprite.sprite_y);
	cub->sprite.transform_y = cub->sprite.inv_det * (-cub->map.plane_y * cub->sprite.sprite_x
								+ cub->map.plane_x * cub->sprite.sprite_y);
	cub->sprite.sprite_screen_x = (int)((cub->map.s_w / 2)
		* (1 + cub->sprite.transform_x / cub->sprite.transform_y));
	cub->sprite.sprite_height = abs((int)(cub->map.s_h / (cub->sprite.transform_y)));
	cub->sprite.draw_start_y = -cub->sprite.sprite_height / 2 + cub->map.s_h / 2;
	if (cub->sprite.draw_start_y < 0)
		cub->sprite.draw_start_y = 0;
	cub->sprite.draw_end_y = cub->sprite.sprite_height / 2 + cub->map.s_h / 2;
	if (cub->sprite.draw_end_y >= cub->map.s_h)
		cub->sprite.draw_end_y = cub->map.s_h - 1;
	cub->sprite.sprite_width = abs((int)(cub->map.s_h / (cub->sprite.transform_y)));
	cub->sprite.draw_start_x = -cub->sprite.sprite_width / 2 + cub->sprite.sprite_screen_x;
	if (cub->sprite.draw_start_x < 0)
		cub->sprite.draw_start_x = 0;
	cub->sprite.draw_end_x = cub->sprite.sprite_width / 2 + cub->sprite.sprite_screen_x;
	if (cub->sprite.draw_end_x >= cub->map.s_w)
		cub->sprite.draw_end_x = cub->map.s_w - 1;
}

void		print_sprite(t_cub *cub)
{
	int		i;
	int		y;
	int		stripe;

	i = -1;
	while (++i < cub->sprite.coll_sprite)
	{
		set_sprite(cub, i);
		stripe = cub->sprite.draw_start_x;
		while (stripe < cub->sprite.draw_end_x)
		{
			cub->map.tex_x = (int)(256 * (stripe - (-cub->sprite.sprite_width / 2
			+ cub->sprite.sprite_screen_x)) * TEXWIDTH / cub->sprite.sprite_width) / 256;
			if (cub->sprite.transform_y > 0 &&
				stripe > 0 && stripe < cub->map.s_w
				&& cub->sprite.transform_y < cub->close_sprite[stripe])
			{
				y = cub->sprite.draw_start_y;
				while (y < cub->sprite.draw_end_y)
				{
					cub->sprite.d = y * 256 - cub->map.s_h
					* 128 + cub->sprite.sprite_height * 128;
					cub->map.tex_y = ((cub->sprite.d * TEXHEIGHT)
									/ cub->sprite.sprite_height) / 256;
					if ((cub->sprite.color = my_mlx_get_pixel(&cub->t_sp,
											cub->map.tex_x, cub->map.tex_y)))
						my_mlx_pixel_put(&cub->data,
								stripe, y, cub->sprite.color);
					y++;
				}
			}
			++stripe;
		}
	}
}
