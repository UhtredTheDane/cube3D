/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:19:51 by anmande           #+#    #+#             */
/*   Updated: 2023/11/03 16:57:58 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"
#include <math.h>
#include "../../includes/data.h"

void	check_interval(t_ray *ray)
{
	if (ray->drawStart < 0)
		ray->drawStart = 0;
	if (ray->drawEnd > 600)
		ray->drawEnd = 600;
}

void	check_ray_dir(t_ray *ray)
{
	if (ray->dir_x == 0)
		ray->deltadist_x = 1e30;
	else
		ray->deltadist_x = fabs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->deltadisty = 1e30;
	else
		ray->deltadisty = fabs(1 / ray->dir_y);
}
void	init_ray(t_ray *ray, t_canvas *canvas, int x)
{
	double	dir_x;
	double	dir_y;
	double camera_x;

	camera_x = 2 * x / (double)800 - 1;
	dir_x = canvas->player->dir_x;
	dir_y = canvas->player->dir_y;
	ray->dir_x = dir_x + canvas->player->plane_x * camera_x;
	ray->dir_y = dir_y + canvas->player->plane_y * camera_x;
	check_ray_dir(ray);
	ray->n_l_hit = floor(canvas->player->y);
	ray->row_hit = floor(canvas->player->x);
	ray->sidedist_x = get_side_dist_x(ray, canvas->player->x);
	ray->sidedisty = get_side_disty(ray, canvas->player->y);
	ray->dw = get_wall_dist(canvas->map, ray);
	ray->lineHeight = (int)(600 / ray->dw);
	ray->drawStart = (ray->lineHeight * -1) / 2 + 600 / 2;
	ray->drawEnd = ray->lineHeight / 2 + 600 / 2;
	check_interval(ray);
}

double	get_wall_dist(t_map *map, t_ray *ray)
{
	while (1)
	{
		if (ray->sidedist_x < ray->sidedisty)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->row_hit += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
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
		return (ray->sidedist_x - ray->deltadist_x);
	else
		return (ray->sidedisty - ray->deltadisty);
}

void	draw_ray(t_canvas *canvas)
{
	t_ray	ray;
	int		cnt;

	cnt = 0;
	while (cnt < 800)
	{
		init_ray(&ray, canvas, cnt);
		win_3d(canvas, &ray, cnt);
		cnt++;
	}
	mlx_put_image_to_window(canvas->mlx, canvas->window, \
	canvas->data.img, 0, 0);
}
