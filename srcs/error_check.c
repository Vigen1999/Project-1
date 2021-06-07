/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:00:50 by vasatrya          #+#    #+#             */
/*   Updated: 2021/05/19 12:00:54 by vasatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	malloc_arrays(t_cub *cub)
{
	if (!(cub->x = malloc(sizeof(float) * cub->sprite.coll_sprite)))
		error("Error\nNo memory allocated", cub);
	if (!(cub->y = malloc(sizeof(float) * cub->sprite.coll_sprite)))
		error("Error\nNo memory allocated", cub);
	if (!(cub->dist = malloc(sizeof(float) * cub->sprite.coll_sprite)))
		error("Error\nNo memory allocated", cub);
	if (!(cub->close_sprite = malloc(sizeof(double) * cub->map.s_w)))
		error("Error\nNo memory allocated", cub);
}

void	get_sprite(t_cub *cub, t_path *path)
{
	int width;
	int height;

	if (!(cub->t_n.img = mlx_xpm_file_to_image(cub->mlx,
											path->n_path, &width, &height)))
		error("Error\nThe north texture is invalid or missing", cub);
	cub->t_n.addr = mlx_get_data_addr(cub->t_n.img,
		&cub->t_n.bits_per_pixel, &cub->t_n.line_length, &cub->t_n.endian);
	if (!(cub->t_s.img = mlx_xpm_file_to_image(cub->mlx,
											path->s_path, &width, &height)))
		error("Error\nThe south texture is invalid or missing", cub);
	cub->t_s.addr = mlx_get_data_addr(cub->t_s.img,
		&cub->t_s.bits_per_pixel, &cub->t_s.line_length, &cub->t_s.endian);
	if (!(cub->t_w.img = mlx_xpm_file_to_image(cub->mlx,
											path->w_path, &width, &height)))
		error("Error\nThe west texture is invalid or missing", cub);
	cub->t_w.addr = mlx_get_data_addr(cub->t_w.img,
		&cub->t_w.bits_per_pixel, &cub->t_w.line_length, &cub->t_w.endian);
	if (!(cub->t_e.img = mlx_xpm_file_to_image(cub->mlx,
											path->e_path, &width, &height)))
		error("Error\nThe east texture is invalid or missing", cub);
	cub->t_e.addr = mlx_get_data_addr(cub->t_e.img,
		&cub->t_e.bits_per_pixel, &cub->t_e.line_length, &cub->t_e.endian);
	if (!(cub->t_sp.img = mlx_xpm_file_to_image(cub->mlx,
											path->sp_path, &width, &height)))
		error("Error\nThe sprite texture is invalid or missing", cub);
	cub->t_sp.addr = mlx_get_data_addr(cub->t_sp.img,
		&cub->t_sp.bits_per_pixel, &cub->t_sp.line_length, &cub->t_sp.endian);
}

void	error_check(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	cub->pl = 5;
	if (cub->map.s_h > 1920 || cub->map.s_w > 1080)
	{
		cub->map.s_w = 1920;
		cub->map.s_h = 1080;
	}
	if (cub->map.s_h < 300 || cub->map.s_w < 300)
		cub->pl = 3;
	if (cub->map.s_h < 100 || cub->map.s_w < 100)
		error("Error\n The resolution is too small", cub);
	while (cub->map.map[i] != NULL)
	{
		j = 0;
		while (cub->map.map[i][j] != '\0')
		{
			if (!(cub->map.map[i][j] == '0' || cub->map.map[i][j] == '1'
			|| cub->map.map[i][j] == '2' || cub->map.map[i][j] == ' '
			|| cub->map.map[i][j] == 'N' || cub->map.map[i][j] == 'S'
			|| cub->map.map[i][j] == 'E' || cub->map.map[i][j] == 'W'))
				error("Error\n The map is invalid", cub);
			if (i == 0 && !(cub->map.map[i][j] == '1'
							|| cub->map.map[i][j] == ' '))
				error("Error\n The map is invalid", cub);
			if (i == cub->map.map_x - 1 && !(cub->map.map[i][j] == '1'
							|| cub->map.map[i][j] == ' '))
				error("Error\n The map is invalid", cub);
			if ((j == 0 || cub->map.map[i][j + 1] == '\0') &&
				!(cub->map.map[i][j] == '1' || cub->map.map[i][j] == ' '))
				error("Error\n The map is invalid", cub);
			if (cub->map.map[i][j] == '0' && (cub->map.map[i + 1][j] == ' ' || cub->map.map[i][j + 1] == ' '
											|| cub->map.map[i - 1][j] == ' ' || cub->map.map[i][j - 1] == ' '))
			{
				printf("%c %d %d\n", cub->map.map[i][j], i, j);
				error("Error\n The map is invalid", cub);
			}
			j++;
		}
		i++;
	}
}
