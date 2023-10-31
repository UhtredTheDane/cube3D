/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:19:51 by anmande           #+#    #+#             */
/*   Updated: 2023/10/31 19:05:27 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"
#include <math.h>
#include "../../includes/data.h"

void	my_mlx_pixel_put(t_canvas *canvas, int x, int y, int color)
{
	char	*dst;

	dst = canvas->data.addr + (y * canvas->data.linlgth
			+ x * (canvas->data.bpp / 8));
	*(unsigned int *)dst = color;
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
	int		value;

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
	mlx_put_image_to_window(canvas->mlx, canvas->win->window2,
		canvas->win->img, 0, 0);
}
