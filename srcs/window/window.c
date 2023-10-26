/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:29:19 by anmande           #+#    #+#             */
/*   Updated: 2023/10/26 13:41:15 by anmande          ###   ########.fr       */
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

void	win_3d(double dm, t_win *win, int i)
{
	double hm = 64.;
	double de = 35;
	double hp = hm / dm * de;
	double hr = HEIGHT / 2;
	double lower = hr - hp / 2;
	double greater = hr + hp / 2;
	// if (i == 400)
	// {
	// 	printf("dm = %f\n", dm);
	// 	printf("hp = %f et hp / 2 = %f\n", hp, test);
	// 	printf ("ray %d: lower %f et greater: %f\n", i, lower, greater);
	// }
	int compt = 0;
	while (compt < lower)
	{
		my_mlx_pixel_put2(win, i, compt, 0xFF0000);
		++compt;
	}
	while (compt < greater)
	{
		//printf("i: %d et compt: %d\n", i, compt);
		my_mlx_pixel_put2(win, i, compt, 0x0000FF);
		++compt;
	}
	while (compt < 600)
	{
		my_mlx_pixel_put2(win, i, compt, 0x808080);
		++compt;
	}
	(void)win;
}

int	ft_close_win(t_canvas *canvas)
{

	exit (0);
	(void)canvas;
}
