/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:29:19 by anmande           #+#    #+#             */
/*   Updated: 2023/11/03 16:58:23 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"

void	init_textures_dir(t_canvas *canvas, t_ray *ray, t_data *wall)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			wall->img = canvas->map->WE_path->img;
		else
			wall->img = canvas->map->EA_path->img;
	}
	else
	{
		if (ray->dir_y < 0)
			wall->img = canvas->map->NO_path->img;
		else
			wall->img = canvas->map->SO_path->img;
	}
	wall->addr = mlx_get_data_addr(wall->img, &wall->bpp,
			&wall->linlgth, &wall->end);
}

void	show_ceiling(t_canvas *canvas, t_ray *ray, int i)
{
	int		compt;

	compt = 0;
	while (compt < ray->drawStart)
	{
		my_mlx_pixel_put(canvas, i, compt, canvas->map->ceiling_color);
		compt++;
	}
}

void	show_mid(t_canvas *canvas, t_ray *ray, int i, t_data *wall)
{
	double	step;
	double	pos;
	int		tex_x;
	int		pixel;
	int		compt;

	step = 1.0 * 64. / ray->lineHeight;
	pos = (ray->drawStart - 600 / 2 + ray->lineHeight / 2) * step;
	tex_x = get_texX(canvas, ray, ray->dw);
	compt = ray->drawStart;
	while (compt < ray->drawEnd)
	{
		pos += step;
		pixel = ((int)pos & (64 - 1)) * wall->linlgth + tex_x * (wall->bpp / 8);
		my_mlx_pixel_put(canvas, i, compt, *(int *)(wall->addr + pixel));
		compt++;
	}
}

void	win_3d(t_canvas *canvas, t_ray *ray, int i)
{
	t_data	wall;
	int		compt;

	init_textures_dir(canvas, ray, &wall);
	show_ceiling(canvas, ray, i);
	show_mid(canvas, ray, i, &wall);
	compt = ray->drawEnd;
	while (compt < 600)
	{
		my_mlx_pixel_put(canvas, i, compt, canvas->map->floor_color);
		compt++;
	}
}

int	ft_close_win(t_canvas *canvas)
{
	destroy_canvas(canvas);
	exit (0);
	return (0);
}
