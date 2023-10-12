/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:19:51 by anmande           #+#    #+#             */
/*   Updated: 2023/10/12 17:35:10 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"

void	draw_player(t_canvas *canvas)
{
	int i;
	int j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			my_mlx_pixel_put(canvas, canvas->player->x + j, canvas->player->y + i, 0x000000);
			j++;
		}
		i++;
	}
}

void	my_mlx_pixel_put(t_canvas *canvas, int x, int y, int color)
{
	char	*dst;

	dst = canvas->addr + (y * canvas->line_len + x * (canvas->bpp / 8));
	*(unsigned int *)dst = color;
}

void	new_image(t_canvas *canvas)
{
	canvas->img = mlx_new_image(canvas->mlx, canvas->map->row_nb * 10, canvas->map->line_nb * 10);
	canvas->addr = mlx_get_data_addr(canvas->img, &canvas->bpp, &canvas->line_len, &canvas->endian);
}

void	draw_squar(t_canvas *canvas, int color, int x_map, int y_map)
{
	int	i;
	int	j;

	i = x_map * 10;
	while (i < (x_map + 1) * 10)
	{
		j = y_map * 10;
		while (j < (y_map + 1) * 10)
		{
			my_mlx_pixel_put(canvas, j, i, color);
			j++;
		}
		i++;
	}
}

void	draw_map(t_canvas *canvas)
{
	size_t	i;
	size_t 	j;

	i = 0;
	while (i < canvas->map->line_nb)
	{
		j = 0;
		while (j < canvas->map->row_nb)
		{
			if (canvas->map->block_map[i][j].type == '1')
				draw_squar(canvas, 0xFF0000, i, j);
			else if (canvas->map->block_map[i][j].type == '0' || canvas->map->block_map[i][j].type == ' ')
				draw_squar(canvas, 0x808080, i, j);
			// else if (canvas->map->block_map[i][j].type == ' ')
			// 	draw_squar(canvas, 0x0000FF, i, j);
			else if (canvas->map->block_map[i][j].type == 'N' || canvas->map->block_map[i][j].type == 'S' || canvas->map->block_map[i][j].type == 'E' || canvas->map->block_map[i][j].type == 'W') 
			{
				draw_squar(canvas, 0x808080, i, j);
				if (canvas->player->x == -1 && canvas->player->y == -1)
				{
					canvas->player->x = j * 10;
					canvas->player->y = i * 10;
				}	
			}
			j++;
		}
		i++;
	}
	draw_player(canvas);
	mlx_put_image_to_window(canvas->mlx, canvas->window, canvas->img, 0, 0);
}
