/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:19:51 by anmande           #+#    #+#             */
/*   Updated: 2023/10/23 16:29:05 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"
#include <math.h>
#define OFFSET 15

double get_side_distX(t_ray *ray, double player_posX)
{
	double sideDistX;
	int num_row;
	
	num_row = trunc(player_posX / SQUARE);
	if (ray->dir_x < 0)
	{
		ray->stepX= -1;
		sideDistX = (player_posX - num_row * SQUARE) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		sideDistX = ((num_row + 1) * SQUARE - player_posX) * ray->deltaDistX;
	}
	return (sideDistX);
}

double get_side_distY(t_ray *ray, double player_posY)
{
	double sideDistY;
	int num_line;
	
	num_line = trunc(player_posY / SQUARE);
	if (ray->dir_y < 0)
	{
		ray->stepY = -1;
		sideDistY = (player_posY - num_line * SQUARE) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		sideDistY = ((num_line + 1) * SQUARE - player_posY) * ray->deltaDistY;
	}
	return (sideDistY);
}

void init_ray(t_ray *ray, t_canvas *canvas, double angle)
{
	ray->dir_x = canvas->player->dir_x * cos(angle) - canvas->player->dir_y * sin(angle);
	ray->dir_y = canvas->player->dir_x * sin(angle) + canvas->player->dir_y * cos(angle);
	ray->deltaDistX = sqrt(1 + pow(ray->dir_y/ray->dir_x, 2.));
	ray->deltaDistY = sqrt(1 + pow(ray->dir_x/ray->dir_y, 2.));
	ray->num_line_hit = trunc(canvas->player->y / SQUARE);
	ray->num_row_hit = trunc(canvas->player->x / SQUARE);
	ray->sideDistX = get_side_distX(ray, canvas->player->x);
	ray->sideDistY = get_side_distY(ray, canvas->player->y);
}

double get_wall_dist(t_canvas *canvas, t_ray *ray)
{
	while (1)
	{
		if (ray->sideDistX < ray->sideDistY)
        {
			ray->sideDistX += ray->deltaDistX * 30.;
          	ray->num_row_hit += ray->stepX;
			ray->side = 0;
        }
        else
        {
          	ray->sideDistY += ray->deltaDistY * 30.; 
          	ray->num_line_hit += ray->stepY;
			ray->side = 1;
		}
        if (canvas->map->block_map[ray->num_line_hit][ray->num_row_hit].type == '1')
			break;
	}
	if(ray->side == 0) 
	 	return (ray->sideDistX - ray->deltaDistX * 30);
    else          
		return (ray->sideDistY - ray->deltaDistY * 30);
}

void    draw_dir_ray(t_canvas *canvas, double angle)
{
	int			i;
	double		ray_x;
	double		ray_y;
	double		dist_mur;
	t_ray	ray;

	init_ray(&ray, canvas, angle);
	dist_mur = get_wall_dist(canvas, &ray);
	printf("angle: %f, total = %f\n", angle, dist_mur);
	ray_x = canvas->player->x;
    ray_y = canvas->player->y;
	i = 0;
	while (i < trunc(dist_mur))
    {
		i++;
		my_mlx_pixel_put(canvas, ray_x, ray_y, 0x0000FF);
		ray_x += ray.dir_x;
		ray_y += ray.dir_y;
	}
}

void	draw_ray(t_canvas *canvas)
{
	double	angle;

	angle = 0;
	while (angle <= M_PI / 6)
	{
	 	draw_dir_ray(canvas, angle);
		if (angle != 0)
			draw_dir_ray(canvas, -angle);
		angle += M_PI / 3840;
	}
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
	canvas->img = mlx_new_image(canvas->mlx, canvas->map->row_nb * SQUARE, canvas->map->line_nb * SQUARE);
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
			if (i == x_map * SQUARE || i == (x_map + 1) * SQUARE - 1 || j == y_map * SQUARE || j == (y_map + 1) *SQUARE - 1)
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

void init_pos_player(t_canvas *canvas, size_t i, size_t j, char dir)
{
	canvas->map->block_map[i][j].type = '0';
	draw_squar(canvas, 0x808080, i, j);
	canvas->player->x = j * SQUARE;
	canvas->player->y = i * SQUARE;
	if (dir == 'N')
	{
		canvas->player->dir_x = 0;
		canvas->player->dir_y = -1;
	}
	else if (dir == 'S')
	{
		canvas->player->dir_x = 0;
		canvas->player->dir_y = 1;
	}
	else if (dir == 'E')
	{
		canvas->player->dir_x = 1;
		canvas->player->dir_y = 0;
	}
	else
	{
		canvas->player->dir_x = -1.;
		canvas->player->dir_y = 0.;
	}
}

void detect_block_type(t_canvas *canvas, size_t i, size_t j)
{
	char block_type;

	block_type = canvas->map->block_map[i][j].type;
	if (block_type == '1')
		draw_squar(canvas, 0xFF0000, i, j);
	else if (block_type == '0' || block_type == ' ')
		draw_squar(canvas, 0x808080, i, j);
	else if (block_type == 'N')
		init_pos_player(canvas, i, j, 'N');
	else if (block_type == 'S')
		init_pos_player(canvas, i, j, 'S');
	else if (block_type == 'E')
		init_pos_player(canvas, i, j, 'E');
	else if (block_type == 'W')
		init_pos_player(canvas, i, j, 'W');
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
			detect_block_type(canvas, i, j);
			j++;
		}
		i++;
	}
	draw_player(canvas);
	draw_ray(canvas);
	mlx_put_image_to_window(canvas->mlx, canvas->window, canvas->img, 0, 0);
}
