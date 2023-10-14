/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:19:51 by anmande           #+#    #+#             */
/*   Updated: 2023/10/14 18:33:18 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"
#include <math.h>
#define OFFSET 10

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
			my_mlx_pixel_put(canvas, fabs(canvas->player->x - OFFSET) + j, fabs(canvas->player->y - OFFSET) + i, 0x000000);
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
	canvas->img = mlx_new_image(canvas->mlx, canvas->map->row_nb * 20, canvas->map->line_nb * 20);
	canvas->addr = mlx_get_data_addr(canvas->img, &canvas->bpp, &canvas->line_len, &canvas->endian);
}

void	draw_squar(t_canvas *canvas, int color, int x_map, int y_map)
{
	int	i;
	int	j;

	i = x_map * 20;
	while (i < (x_map + 1) * 20)
	{
		j = y_map * 20;
		while (j < (y_map + 1) * 20)
		{
			my_mlx_pixel_put(canvas, j, i, color);
			j++;
		}
		i++;
	}
}

void init_pos_player(t_canvas *canvas, size_t i, size_t j)
{
	canvas->map->block_map[i][j].type = '0';	
	draw_squar(canvas, 0x808080, i, j);
	canvas->player->x = j * 20;
	canvas->player->y = i * 20;
}

void	draw_map(t_canvas *canvas)
{
	size_t	i;
	size_t 	j;
	char block_type;

	i = 0;
	while (i < canvas->map->line_nb)
	{
		j = 0;
		while (j < canvas->map->row_nb)
		{
			block_type = canvas->map->block_map[i][j].type;
			if (block_type == '1')
				draw_squar(canvas, 0xFF0000, i, j);
			else if (block_type == '0' || block_type == ' ')
				draw_squar(canvas, 0x808080, i, j);
			else if (block_type == 'N')
			{
				init_pos_player(canvas, i, j);
				canvas->player->dir_x = 0;
				canvas->player->dir_y = -1;
			}
			else if (block_type == 'S')
			{
				init_pos_player(canvas, i, j);
				canvas->player->dir_x = 0;
				canvas->player->dir_y = 1;

				init_pos_player(canvas, i, j);
			}
			else if(block_type == 'E')
			{
				init_pos_player(canvas, i, j);
				canvas->player->dir_x = 1;
				canvas->player->dir_y = 0;
			}
			else if (block_type == 'W') 
			{	
				init_pos_player(canvas, i, j);
				canvas->player->dir_x = -1.;
				canvas->player->dir_y = 0.;
			}
			j++;
		}
		i++;
	}
	draw_player(canvas);
	mlx_put_image_to_window(canvas->mlx, canvas->window, canvas->img, 0, 0);
}
