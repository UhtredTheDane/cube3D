/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:29:19 by anmande           #+#    #+#             */
/*   Updated: 2023/10/29 11:37:23 by agengemb         ###   ########.fr       */
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
	double	hm;
	double	de;
	double	hp;
	double	hr;
	int		compt;
	double wallX;

	t_data wall;
	hm = 64.;
	de = 20.;
	hp = hm / dm * de;
	hr = 300.;
	compt = 0;
	
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
	int texX = trunc(wallX * 64);
	if (ray->side == 0 && ray->dir_x < 0)
		texX = 64 - texX - 1;
	else if (ray->side == 1 && ray->dir_y > 0)
		texX = 64 - texX - 1;

	while (compt++ < hr - hp / 2)//lower
		my_mlx_pixel_put2(canvas->win, i, compt, 0xFF0000);
	while (compt++ < hr + hp / 2 && compt < 600)//greater
	{
		int texY = (compt * 2 - 600 + hp) * (64/2) / hp;
		int pixel = texY * wall.line_length + texX * (wall.bpp / 8);
		my_mlx_pixel_put2(canvas->win, i, compt,
					*(int *)(wall.addr + pixel));
	}
	while (compt++ < 600)
		my_mlx_pixel_put2(canvas->win, i, compt, 0x808080);
}

int	ft_close_win(t_canvas *canvas)
{

	exit (0);
	(void)canvas;
}
