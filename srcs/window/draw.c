/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:19:51 by anmande           #+#    #+#             */
/*   Updated: 2023/10/27 16:16:08 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"
#include <math.h>
#include "../../includes/data.h"
#define OFFSET 15

double	get_side_dist_x(t_ray *ray, double player_posx)
{
	double	sidedist_x;
	int		num_row;

	num_row = trunc(player_posx / SQUARE);
	if (ray->dir_x < 0)
	{
		ray->stepx = -1;
		sidedist_x = (player_posx - num_row * SQUARE) * ray->deltadist_x;
	}
	else
	{
		ray->stepx = 1;
		sidedist_x = ((num_row + 1) * SQUARE - player_posx) * ray->deltadist_x;
	}
	return (sidedist_x);
}

double	get_side_disty(t_ray *ray, double player_posY)
{
	double	sidedisty;
	int		num_line;

	num_line = trunc(player_posY / SQUARE);
	if (ray->dir_y < 0)
	{
		ray->stepY = -1;
		sidedisty = (player_posY - num_line * SQUARE) * ray->deltadisty;
	}
	else
	{
		ray->stepY = 1;
		sidedisty = ((num_line + 1) * SQUARE - player_posY) * ray->deltadisty;
	}
	return (sidedisty);
}

void	init_ray(t_ray *ray, t_canvas *canvas, double angle)
{
	double	dir_x;
	double	dir_y;

	dir_x = canvas->player->dir_x;
	dir_y = canvas->player->dir_y;
	ray->dir_x = dir_x * cos(angle) - dir_y * sin(angle);
	ray->dir_y = dir_x * sin(angle) + dir_y * cos(angle);
	ray->deltadist_x = sqrt(1 + pow(ray->dir_y / ray->dir_x, 2.));
	ray->deltadisty = sqrt(1 + pow(ray->dir_x / ray->dir_y, 2.));
	ray->n_l_hit = trunc(canvas->player->y / SQUARE);
	ray->row_hit = trunc(canvas->player->x / SQUARE);
	ray->sidedist_x = get_side_dist_x(ray, canvas->player->x);
	ray->sidedisty = get_side_disty(ray, canvas->player->y);
}

double	get_wall_dist(t_map *map, t_ray *ray)
{
	while (1)
	{
		if (ray->sidedist_x < ray->sidedisty)
		{
			ray->sidedist_x += ray->deltadist_x * 30.;
			ray->row_hit += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty * 30.;
			ray->n_l_hit += ray->stepY;
			ray->side = 1;
		}
		if (ray->n_l_hit < 0 || ray->n_l_hit >= (int)map->line_nb
			|| ray->row_hit < 0 || ray->row_hit >= (int)map->row_nb)
			return (0);
		if (map->block_map[ray->n_l_hit][ray->row_hit].type == '1')
			break ;
	}
	if (ray->side == 0)
		return (ray->sidedist_x - ray->deltadist_x * 30);
	else
		return (ray->sidedisty - ray->deltadisty * 30);
}

double	draw_dir_ray(t_canvas *canvas, double angle)
{
	double		dist_mur;
	t_ray		ray;

	init_ray(&ray, canvas, angle);
	dist_mur = get_wall_dist(canvas->map, &ray);
	dist_mur = dist_mur * cos(angle);
	return (dist_mur);
}

void	draw_ray(t_canvas *canvas)
{
	double	angle;
	int		i;
	int		j;
	int value;

	value = 800 / 2 * 6;
	angle = 0;
	i = 800 / 2;
	j = i - 1;
	while (angle < M_PI / 6)
	{
		win_3d(draw_dir_ray(canvas, angle), canvas->win, i++);
		if (angle != 0.)
			win_3d (draw_dir_ray(canvas, -angle), canvas->win, j--);
		angle += M_PI / value;
	}
	mlx_put_image_to_window(canvas->mlx, canvas->win->window2, canvas->win->img, 0, 0);
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
			++j;
		}
		++i;
	}
}

void	my_mlx_pixel_put(t_canvas *canvas, int x, int y, int color)
{
	char	*dst;

	dst = canvas->data.addr + (y * canvas->data.line_length + x * (canvas->data.bpp / 8));
	*(unsigned int *)dst = color;
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
	canvas->player->x = j * SQUARE + 15;
	canvas->player->y = i * SQUARE + 15;
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
	mlx_put_image_to_window(canvas->mlx, canvas->window, canvas->data.img, 0, 0);
}
