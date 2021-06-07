/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:01:44 by vasatrya          #+#    #+#             */
/*   Updated: 2021/05/19 12:01:46 by vasatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_mini_map(t_cub *cub)
{
	int	m_map_x = cub->pl;
	int	m_map_y = cub->map.s_h - (cub->pl*cub->map.map_x) - cub->pl;
	int mdx = m_map_x;
	int mdy = m_map_y;
	int rem = cub->map.map_y;

	for (int i = 0; i < cub->map.map_x; i++)
	{	
		mdx = m_map_x;
		cub->map.map_y = rem;
		for (int j = 0; j < cub->map.map_y; j++)
		{
			while (ft_isspace(cub->map.map[i][j]))
			{	
				mdx += cub->pl - 1;
				j++;
				cub->map.map_y++;
			}
			if (cub->map.map[i][j] == '1')
			{
				for (int u = 0; u < cub->pl; u++)
					for (int v = 0; v < cub->pl; v++)
					{
						if (u == 0 || u == cub->pl - 1)
							my_mlx_pixel_put(&cub->data, mdx + j + v, mdy + i + u, 0xa61c1c);
						if (v == 0 || v == cub->pl - 1)
							my_mlx_pixel_put(&cub->data, mdx + j + v, mdy + i + u, 0xa61c1c);
					}
			}
			else if (cub->map.map[i][j] == '2')
			{
				for (int u = 0; u < cub->pl; u++)
					for (int v = 0; v < cub->pl; v++)
					{
						if (u == 0 || u == cub->pl - 1)
							my_mlx_pixel_put(&cub->data, mdx + j + v, mdy + i + u, 0xdbeb00);
						if (v == 0 || v == cub->pl - 1)
							my_mlx_pixel_put(&cub->data, mdx + j + v, mdy + i + u, 0xdbeb00);
					}
			}
			else
				for (int u = 0; u < cub->pl; u++)
					for (int v = 0; v < cub->pl; v++)
					{
						my_mlx_pixel_put(&cub->data, mdx + j + v, mdy + i + u, 0x2d47a6);
						if (u == 0 || u == cub->pl - 1)
							my_mlx_pixel_put(&cub->data, mdx + j + v, mdy + i + u, 0x2f00bd);
						if (v == 0 || v == cub->pl - 1)
							my_mlx_pixel_put(&cub->data, mdx + j + v, mdy + i + u, 0x2f00bd);
					}
			mdx += cub->pl - 1;
		}
		mdy += cub->pl - 1;
	}
	//player
	int size = cub->pl -2;
	for (int u = 0; u < size; u++)
	{
		for (int v = 0; v < size; v++)
		{
			my_mlx_pixel_put(&cub->data, m_map_x + cub->map.p_y * cub->pl + v
			- size / 2, m_map_y + cub->map.p_x * cub->pl + u - size / 2, 0x00ff0d);
			if (u == 0 || u == size - 1)
				my_mlx_pixel_put(&cub->data, m_map_x + cub->map.p_y * cub->pl + v
			- size / 2, m_map_y + cub->map.p_x * cub->pl + u - size / 2, 0x1ca623);
			if (v == 0 || v == size - 1)
				my_mlx_pixel_put(&cub->data, m_map_x + cub->map.p_y * cub->pl + v
			- size / 2, m_map_y + cub->map.p_x * cub->pl + u - size / 2, 0x1ca623);
		}
	}
}
