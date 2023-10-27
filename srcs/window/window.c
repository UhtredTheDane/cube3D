/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:29:19 by anmande           #+#    #+#             */
/*   Updated: 2023/10/27 14:14:27 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"

void	my_mlx_pixel_put2(t_win *win, int x, int y, int color)
{
	char	*dst;

	//printf("x: %d et y: %d\n", x, y);
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

void	win_3d(double dm, t_win *win, int i)
{
	double hm = 64.;
	double de = 40.;
	double hp = hm / dm * de;
	double hr = 300.;
	double lower = hr - hp / 2;
	double greater = hr + hp/2;
	int compt = 0;
	while (compt < lower)
	{
		my_mlx_pixel_put2(win, i, compt, 0xFF0000);
		++compt;
	}
	while (compt < greater && compt < 600)
	{
		my_mlx_pixel_put2(win, i, compt, 0x0000FF);
		++compt;
	}
	while (compt < 600)
	{
		my_mlx_pixel_put2(win, i, compt, 0x808080);
		++compt;
	}
}

int	ft_close_win(t_canvas *canvas)
{

	exit (0);
	(void)canvas;
}
