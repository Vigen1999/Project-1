/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_shot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:01:22 by vasatrya          #+#    #+#             */
/*   Updated: 2021/05/19 12:01:24 by vasatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static	void	fill_screen(int fd, t_cub *cub)
{
	int i;
	int j;
	int color;

	i = cub->map.s_h;
	while (--i >= 0)
	{
		j = -1;
		while (++j < cub->map.s_w)
		{
			color = my_mlx_get_pixel(&cub->data, j, i);
			write(fd, &color, 4);
		}
	}
	exit(0);
}

static	void	screenshot_norm(int fd, int all_pix, int zero, int size)
{
	short	plane;

	plane = 1;
	write(fd, &plane, 2);
	plane = 32;
	write(fd, &plane, 2);
	write(fd, &zero, 4);
	write(fd, &size, 4);
	all_pix = 1000;
	write(fd, &all_pix, 4);
	write(fd, &all_pix, 4);
	write(fd, &zero, 4);
	write(fd, &zero, 4);
}

void			screen_shot(t_cub *cub)
{
	int		fd;
	int		all_pix;
	int		zero;
	int		pos_pix;
	int		size;

	fd = open("screen.bmp", O_CREAT | O_RDWR, 0666);
	all_pix = cub->map.s_w * cub->map.s_h * 4 + 54;
	zero = 0;
	pos_pix = 54;
	size = cub->map.s_w * cub->map.s_h;
	write(fd, "BM", 2);
	write(fd, &all_pix, 4);
	write(fd, &zero, 4);
	write(fd, &pos_pix, 4);
	pos_pix = 40;
	write(fd, &pos_pix, 4);
	write(fd, &cub->map.s_w, 4);
	write(fd, &cub->map.s_h, 4);
	screenshot_norm(fd, all_pix, zero, size);
	fill_screen(fd, cub);
}
