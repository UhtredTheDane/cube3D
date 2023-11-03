/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:29:19 by anmande           #+#    #+#             */
/*   Updated: 2023/11/03 15:42:04 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"

void	my_mlx_pixel_put2(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->line_len + x * (win->bpp / 8));
	*(unsigned int *)dst = color;
}

void	win_3d(double dm, t_canvas *canvas, t_ray *ray, int i)
{
	int		compt;
	double	wallX;
	t_data	wall;

	compt = 0;
	(void) ray;
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			wall.img = canvas->map->WE_path->img;
		else
			wall.img = canvas->map->EA_path->img;
	}
	else
	{
		if (ray->dir_y < 0)
			wall.img = canvas->map->NO_path->img;
		else
			wall.img = canvas->map->SO_path->img;
	}
	wall.addr = mlx_get_data_addr(wall.img, &wall.bpp,
			&wall.linlgth, &wall.end);
	if (ray->side == 1)
		wallX = canvas->player->x + dm * ray->dir_x;
	else
		wallX = canvas->player->y + dm * ray->dir_y;
	wallX -= trunc(wallX);
	int texX = trunc(wallX * 64.);
	if (ray->side == 0 && ray->dir_x < 0)
		texX = 64 - texX - 1;
	else if (ray->side == 1 && ray->dir_y > 0)
		texX = 64 - texX - 1;
	
	int lineHeight = (int)(600 / dm);
	int drawStart = -lineHeight / 2 + 600 / 2;
    if(drawStart < 0)
		drawStart = 0;
	
	while (compt < drawStart)
	{
		my_mlx_pixel_put(canvas, i, compt, canvas->map->ceiling_color);
		compt++;
	}

	double step = 1.0 * 64. / lineHeight;
	
    int drawEnd = lineHeight / 2 + 600 / 2;
    if(drawEnd >= 600)
		drawEnd = 600;
	double pos = (drawStart - 600 / 2 + lineHeight / 2) * step;
	while (compt < drawEnd)
	{
		int texY = (int)pos & (64 - 1);
		pos += step;
		int pixel = texY * wall.linlgth + texX * (wall.bpp / 8);
		my_mlx_pixel_put(canvas, i, compt, *(int *)(wall.addr + pixel));
		compt++;
	}
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
