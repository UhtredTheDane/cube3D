/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:19:51 by anmande           #+#    #+#             */
/*   Updated: 2023/11/02 15:51:12 by anmande          ###   ########.fr       */
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

void	init_ray(t_ray *ray, t_canvas *canvas, int x)
{
	double	dir_x;
	double	dir_y;

	double camera_x = 2 * x / (double)800 - 1;
	dir_x = canvas->player->dir_x;
	dir_y = canvas->player->dir_y;
	ray->dir_x = dir_x + canvas->player->plane_x * camera_x;
	ray->dir_y = dir_y + canvas->player->plane_y * camera_x;
	ray->deltadist_x = fabs(1 / ray->dir_x);
	ray->deltadisty = fabs(1 / ray->dir_y);
	ray->n_l_hit = floor(canvas->player->y);
	ray->row_hit = floor(canvas->player->x);
	ray->sidedist_x = get_side_dist_x(ray, canvas->player->x);
	ray->sidedisty = get_side_disty(ray, canvas->player->y);
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

double	draw_dir_ray(t_canvas *canvas, t_ray *ray, double angle)
{
	double		dist_mur;

	(void) angle;
	dist_mur = get_wall_dist(canvas->map, ray);
	return (dist_mur);
}

void	draw_ray(t_canvas *canvas)
{
	//double	angle;
	//int		i;
	//int		j;
	//int value;
	t_ray		ray;

	//value = 800 / 2 * 4;
	//angle = 0;
	//i = 800 / 2;
	//j = i - 1;
	int cnt = 0;
	while (cnt < 800)
	{
		init_ray(&ray, canvas, cnt);
		win_3d(get_wall_dist(canvas->map, &ray), canvas, &ray, cnt);
		/*if (angle != 0.)
		{
			init_ray(&ray, canvas, -angle);
			win_3d(draw_dir_ray(canvas, &ray, -angle), canvas, &ray, j--);
		}*/
		//angle += (M_PI / 4) / 400;
		cnt++;
	}
	mlx_put_image_to_window(canvas->mlx, canvas->window, canvas->data.img, 0, 0);
}
