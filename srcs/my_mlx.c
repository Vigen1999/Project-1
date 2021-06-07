/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:01:11 by vasatrya          #+#    #+#             */
/*   Updated: 2021/05/19 12:01:14 by vasatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

unsigned int	my_mlx_get_pixel(t_data *data, int x, int y)
{
	unsigned int	color;
	char			*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	color = *(unsigned int*)dst;
	return (color);
}

int				my_mlx_create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int				my_mlx_close_win(t_cub *cub)
{
	exit(0);
	mlx_destroy_window(cub->mlx, cub->win);
	return (0);
}

void			error(char *str, t_cub *cub)
{
	(void)cub;
	printf("%s\n", str);
	exit(1);
}
