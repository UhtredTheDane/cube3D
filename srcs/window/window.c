/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:29:19 by anmande           #+#    #+#             */
/*   Updated: 2023/10/30 13:12:47 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"

void	my_mlx_pixel_put2(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->line_len + x * (win->bpp / 8));
	*(unsigned int *)dst = color;
}

t_win	*init_window(void *mlx)
{
	t_win	*win;

	win = malloc(sizeof(t_win));
	if (!win)
		return (NULL);
	win->window2 = mlx_new_window(mlx, 800, 600, "cub3D");
	win->img = mlx_new_image(mlx, 800, 600);
	win->addr = mlx_get_data_addr(win->img, &win->bpp, &win->line_len, &win->endian);
	return (win);
}

void	win_3d(double dm, t_canvas *canvas, t_ray *ray, int i)
{
	int		compt;
	double wallX;

	t_data wall;
	//dm *= cos(ray->angle);
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
			&wall.line_length, &wall.endian);
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
	
	while (compt < drawStart)//lower
	{
		my_mlx_pixel_put2(canvas->win, i, compt, 0xFF0000);
		compt++;
	}

	double step = 1.0 * 64. / lineHeight;
	
    int drawEnd = lineHeight / 2 + 600 / 2;
    if(drawEnd >= 600)
		drawEnd = 600 - 1;
	double pos = (drawStart - 600 / 2 + lineHeight / 2) * step;
	while (compt < drawEnd)//greater
	{
		int texY = (int)pos & (64 - 1);
		pos += step;
		int pixel = texY * wall.line_length + texX * (wall.bpp / 8);
		my_mlx_pixel_put2(canvas->win, i, compt, *(int *)(wall.addr + pixel));
		compt++;
	}
	while (compt < 600)
	{
		my_mlx_pixel_put2(canvas->win, i, compt, 0x808080);
		compt++;
	}
}

int	ft_close_win(t_canvas *canvas)
{
	exit (0);
	(void)canvas;
}
