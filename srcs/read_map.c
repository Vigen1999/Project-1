/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:01:54 by vasatrya          #+#    #+#             */
/*   Updated: 2021/05/19 12:01:57 by vasatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*digit_move(char *st)
{
	while (ft_isdigit(*st))
		st++;
	return (st);
}

void	read_map(t_cub *cub, t_path *path, char *line)
{
	int		i;
	int		j;
	char	c;
	char	c_p;

	i = 0;
	j = 0;
	if (*line == 'R')
	{
		line++;
		while (ft_isspace(*line))
			line++;
		cub->map.s_w = ft_atoi(line);
		while (!ft_isspace(*line))
			line++;
		while (ft_isspace(*line))
			line++;
		cub->map.s_h = ft_atoi(line);
	}
	else if (*line == 'N' || *line == 'S' || *line == 'W' || *line == 'E')
	{
		c = *line;
		c_p = *(++line);
		while (*line != '.')
			line++;
		if (c == 'N')
			path->n_path = line;
		else if (c == 'S' && c_p == 'O')
			path->s_path = line;
		else if (c == 'W')
			path->w_path = line;
		else if (c == 'E')
			path->e_path = line;
		else if (c == 'S')
			path->sp_path = line;
	}
	else if (*line == 'F' || *line == 'C')
	{
		c = *line;
		while (line[++i] != '\0')
			if (!(ft_isdigit(line[i]) || line[i] == ' ' || line[i] == ','))
				error("Error\n Wrong RGB", cub);
		while (*line)
		{
			if (ft_isdigit(*line))
			{
				if (j == 0)
				{
					cub->rgb.r = ft_atoi(line);
					line = digit_move(line);
					j++;
				}
				else if (j == 1)
				{
					cub->rgb.g = ft_atoi(line);
					line = digit_move(line);
					j++;
				}
				else if (j == 2)
				{
					cub->rgb.b = ft_atoi(line);
					line = digit_move(line);
					j++;
				}
			}
			line++;
		}
		if (c == 'C')
			cub->sky_rgb = my_mlx_create_rgb(cub->rgb.r,
												cub->rgb.g, cub->rgb.b);
		else
			cub->ground_rgb = my_mlx_create_rgb(cub->rgb.r,
												cub->rgb.g, cub->rgb.b);
	}
	else if (ft_isdigit(*line) || ft_isspace(*line))
	{
		while (ft_isspace(line[i]))
			i++;
		if (ft_isdigit(line[i]))
		{
			cub->map.map[cub->map.map_x] = line;
			cub->map.map_y = ft_strlen(line);
			if (ft_strlen(line) < cub->map.map_y)
				cub->map.map_y = ft_strlen(line);
			while (cub->map.map[cub->map.map_x][j] != '\0')
			{
				if (cub->map.map[cub->map.map_x][j] == 'N'
				|| cub->map.map[cub->map.map_x][j] == 'S'
				|| cub->map.map[cub->map.map_x][j] == 'W'
				|| cub->map.map[cub->map.map_x][j] == 'E')
				{
					if (cub->map.map[cub->map.map_x][j] == 'N')
					{
						cub->map.dir_y = 0;
						cub->map.dir_x = -1;
						cub->map.plane_y = 0.66;
						cub->map.plane_x = 0;
					}
					else if (cub->map.map[cub->map.map_x][j] == 'S')
					{
						cub->map.dir_y = 0;
						cub->map.dir_x = 1;
						cub->map.plane_y = -0.66;
						cub->map.plane_x = 0;
					}
					else if (cub->map.map[cub->map.map_x][j] == 'W')
					{
						cub->map.dir_y = -1;
						cub->map.dir_x = 0;
						cub->map.plane_y = 0;
						cub->map.plane_x = -0.66;
					}
					else if (cub->map.map[cub->map.map_x][j] == 'E')
					{
						cub->map.dir_y = 1;
						cub->map.dir_x = 0;
						cub->map.plane_y = 0;
						cub->map.plane_x = 0.66;
					}
					cub->map.map[cub->map.map_x][j] = '0';
					cub->map.p_x = cub->map.map_x + SCL;
					cub->map.p_y = j + SCL;
				}
				j++;
			}
			cub->map.map_x++;
		}
	}
}
