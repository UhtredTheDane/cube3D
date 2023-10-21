/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:19:51 by anmande           #+#    #+#             */
/*   Updated: 2023/10/21 01:57:33 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"
#include <math.h>
#define OFFSET 15

//#define PI 3.14159265359

// int	nb_draw(t_canvas *canvas ,double dir)
// {
// 	double	i;

// 	i = dir / SQUARE;
// }

double get_side_distX(double player_posX, double dx, double deltaDistX, int *stepX)
{
	double sideDistX;
	int num_row;
	
	num_row = trunc(player_posX / SQUARE);
	if (dx < 0)
	{
		*stepX = -1;
		sideDistX = (player_posX - num_row * SQUARE) * deltaDistX;
	}
	else
	{
		*stepX = 1;
		sideDistX = ((num_row + 1) * SQUARE - player_posX) * deltaDistX;
	}
	return (sideDistX);
}

double get_side_distY(double player_posY, double dy, double deltaDistY, int *stepY)
{
	double sideDistY;
	int num_line;
	
	num_line = trunc(player_posY / SQUARE);
	if (dy < 0)
	{
		*stepY = -1;
		sideDistY = (player_posY - num_line * SQUARE) * deltaDistY;
	}
	else
	{
		*stepY = 1;
		sideDistY = ((num_line + 1) * SQUARE - player_posY) * deltaDistY;
	}
	return (sideDistY);
}

double calculate_wall_dist(t_canvas *canvas, double deltaDistX, double deltaDistY)
{
	int side;
	int num_line;
	int num_row;
	int stepX;
	int stepY;
	double sideDistX;
	double sideDistY;

	sideDistX = get_side_distX(canvas->player->x, canvas->player->dir_x, deltaDistX, &stepX);
	sideDistY = get_side_distY(canvas->player->y, canvas->player->dir_y, deltaDistY, &stepY);
	num_line = trunc(canvas->player->y / SQUARE);
	num_row = trunc(canvas->player->x / SQUARE);
	side = 0;
	while (1)
	{
		if (sideDistX < sideDistY)
        {
			sideDistX += deltaDistX * 30.;
          	num_row += stepX;
			side = 0;
        }
        else
        {
          	sideDistY += deltaDistY * 30.; 
          	num_line += stepY;
			side = 1;
		}
        if (canvas->map->block_map[num_line][num_row].type == '1')
			break;
	}
	if(side == 0) 
	 	return (sideDistX - deltaDistX * 30);
    else          
		return (sideDistY - deltaDistY * 30);
}

double get_wall_dist(t_canvas *canvas)
{
	double deltaDistX;
	double deltaDistY;

	deltaDistX = sqrt(1 + pow(canvas->player->dir_y/canvas->player->dir_x, 2.));
	deltaDistY = sqrt(1 + pow(canvas->player->dir_x/canvas->player->dir_y, 2.));
	return (calculate_wall_dist(canvas, deltaDistX, deltaDistY));
}

void    draw_ray(t_canvas *canvas)
{
	int			i;
	double		ray_x;
	double		ray_y;
	double		dist_mur;
	
	dist_mur = get_wall_dist(canvas);
	printf("total = %f\n", dist_mur);
	ray_x = canvas->player->x;
    ray_y = canvas->player->y;
	i = 0;
	while (i < trunc(dist_mur))
    {
		i++;
		my_mlx_pixel_put(canvas, ray_x, ray_y, 0x0000FF);
		ray_x += canvas->player->dir_x;
		ray_y += canvas->player->dir_y;
	}
}

/*
void	draw_ray(t_canvas *canvas)
{
	double	angle;

	//angle = canvas->player->angle;
	angle = 0;
	draw_dir_ray(canvas, angle);
	while (angle <= M_PI / 6)
	{
	 	draw_dir_ray(canvas, angle);
	 	draw_dir_ray(canvas, -angle);
		angle += M_PI / 72;
	}
}*/

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
}

void init_pos_player(t_canvas *canvas, size_t i, size_t j)
{
	canvas->map->block_map[i][j].type = '0';	
	draw_squar(canvas, 0x808080, i, j);
	canvas->player->x = j *SQUARE;
	canvas->player->y = i *SQUARE;
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
