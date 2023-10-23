/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:19:51 by anmande           #+#    #+#             */
/*   Updated: 2023/10/23 14:04:13 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"
#include <math.h>
#define OFFSET 15

//#define PI 3.14159265359

// int	distance_draw(t_canvas *canvas ,double dist)
// {
// 	int		i;

// 	i = canvas->player->x / SQUARE;
// 	canvas->dist = dist * ;
// }

void    draw_dir_ray(t_canvas *canvas, double angle)
{
	int			i;
	double		ray_x;
	double		ray_y;
	double		dx;
	double		dy;
	double		max_value;

    ray_x = canvas->player->x;
    ray_y = canvas->player->y;
	i = 0;

	dx = cos(angle) * canvas->player->dir_x - sin(angle) * canvas->player->dir_y;
	dy = sin(angle) * canvas->player->dir_x + cos(angle) * canvas->player->dir_y;

    max_value = fmax(fabs(dx), fabs(dy));
    dx /= max_value;
    dy /= max_value;
    ray_x += dx;
    ray_y += dy;
	// calcul distance 
	double deltaDistX = sqrt(1 + pow(dy/dx, 2.));
	double deltaDistY = sqrt(1 + pow(dx/dy, 2.));
	int num_line = canvas->player->y /SQUARE;
	int num_row = canvas->player->x /SQUARE;
	double sideDistX;
	double sideDistY;
	//double disTotal;
	int stepX;
	int stepY;

	if (dx < 0)
	{
		stepX = -1;
		sideDistX = (canvas->player->x - num_row * SQUARE) * deltaDistX;
	}
	else
	{
		stepX = 1;
		sideDistX = ((num_row + 1) *SQUARE - canvas->player->x) * deltaDistX;
	}
	if (dy < 0)
	{
		stepY = -1;
		sideDistY = (canvas->player->y - num_line * SQUARE) * deltaDistY;
	}
	else
	{
		stepY = 1;
		sideDistY = ((num_line + 1) * SQUARE - canvas->player->y) * deltaDistY;
	}
	while (1)
	{
		if (sideDistX < sideDistY)
		{
			sideDistX += deltaDistX * SQUARE;
			num_row += stepX;
		}
		else
		{
			sideDistY += deltaDistY * SQUARE;
			num_line += stepY;
		}
        //Check if ray has hit a wall
		if (canvas->map->block_map[num_line][num_row].type == '1') 
			break ;
	}
	// if (sideDistX <= sideDistY)
	// 	disTotal = sideDistX;
	// if (sideDistX > sideDistY)
	// 		disTotal = sideDistY;
	//printf("distance total x = %f\n", disTotal);
	i = 0;
	while ((i < sideDistX && i < sideDistY) && i < 100)
    {
		i++;
		my_mlx_pixel_put(canvas, ray_x, ray_y, 0x0000FF);
		ray_x += dx;
		ray_y += dy;
	}
	printf("====================================\n");
	printf("x = %f et y = %f\n", sideDistX, sideDistY);
	printf("i = %d\n", i);
}

void	draw_ray(t_canvas *canvas)
{
	double	angle;

	angle = 0;
	draw_dir_ray(canvas, angle);
	// while (angle <= M_PI / 6)
	// {
	//  	draw_dir_ray(canvas, angle);
	//  	draw_dir_ray(canvas, -angle);
	// 	angle += M_PI / 72;
	// }
}

void	draw_player(t_canvas *canvas)
{
	int i;
	int j;

	i = 13;
	while (i < 18)
	{
		j = 13;
		while (j < 18)
		{
			my_mlx_pixel_put(canvas, canvas->player->x - OFFSET + j, canvas->player->y - OFFSET + i, 0x000000);
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
	canvas->img = mlx_new_image(canvas->mlx, canvas->map->row_nb *SQUARE, canvas->map->line_nb *SQUARE);
	canvas->addr = mlx_get_data_addr(canvas->img, &canvas->bpp, &canvas->line_len, &canvas->endian);
}

void	draw_squar(t_canvas *canvas, int color, int x_map, int y_map)
{
	int	i;
	int	j;

	i = x_map *SQUARE;
	while (i < (x_map + 1) *SQUARE)
	{
		j = y_map *SQUARE;
		while (j < (y_map + 1) *SQUARE)
		{
			if (i == x_map *SQUARE || i == (x_map + 1) *SQUARE - 1 || j == y_map *SQUARE || j == (y_map + 1) *SQUARE - 1)
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

void init_pos_player(t_canvas *canvas, size_t i, size_t j)
{
	canvas->map->block_map[i][j].type = '0';
	draw_squar(canvas, 0x808080, i, j);
	canvas->player->x = j * SQUARE + SQUARE / 2;
	canvas->player->y = i * SQUARE + SQUARE / 2;
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
			else if (block_type == 'E')
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
	draw_ray(canvas);
	mlx_put_image_to_window(canvas->mlx, canvas->window, canvas->img, 0, 0);
}
