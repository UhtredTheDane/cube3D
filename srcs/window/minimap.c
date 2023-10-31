/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:24:53 by anmande           #+#    #+#             */
/*   Updated: 2023/10/31 19:06:12 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"
#define OFFSET 15

void	draw_squar(t_canvas *canvas, int color, int x_map, int y_map)
{
	int	i;
	int	j;

	i = x_map * SQUARE;
	while (i < (x_map + 1) * SQUARE)
	{
		j = y_map * SQUARE;
		while (j < (y_map + 1) * SQUARE)
		{
			if (i == x_map * SQUARE || i == (x_map + 1) * SQUARE - 1 || \
			j == y_map * SQUARE || j == (y_map + 1) * SQUARE - 1)
				my_mlx_pixel_put(canvas, j, i, 0x000000);
			else
				my_mlx_pixel_put(canvas, j, i, color);
			j++;
		}
		i++;
	}
	(void)color;
	(void)canvas;
}

void	draw_player(t_canvas *canvas)
{
	int	i;
	int	j;

	i = 13;
	while (i < 18)
	{
		j = 13;
		while (j < 18)
		{
			my_mlx_pixel_put(canvas, canvas->player->x - OFFSET + j,
				canvas->player->y - OFFSET + i, 0x000000);
			++j;
		}
		++i;
	}
}

void	draw_map(t_canvas *canvas)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < canvas->map->line_nb)
	{
		j = 0;
		while (j < canvas->map->row_nb)
		{
			detect_block_type(canvas, i, j);
			j++;
		}
		i++;
	}
	draw_player(canvas);
	draw_ray(canvas);
	mlx_put_image_to_window(canvas->mlx, \
		canvas->window, canvas->data.img, 0, 0);
}
