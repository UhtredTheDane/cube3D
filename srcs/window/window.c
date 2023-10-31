/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:29:19 by anmande           #+#    #+#             */
/*   Updated: 2023/10/31 18:08:45 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"

void	my_mlx_pixel_put2(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->linl + x * (win->bpp / 8));
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
	win->addr = mlx_get_data_addr(win->img, &win->bpp, &win->linl, &win->end);
	return (win);
}

void	win_3d(double dm, t_win *win, int i)
{
	double	hm;
	double	de;
	double	hp;
	double	hr;
	int		compt;

	hm = 64.;
	de = 40.;
	hp = hm / dm * de;
	hr = 300.;
	compt = 0;
	while (compt++ < hr - hp / 2)
		my_mlx_pixel_put2(win, i, compt, 0xFF0000);
	while (compt++ < hr + hp / 2 && compt < 600)
		my_mlx_pixel_put2(win, i, compt, 0x0000FF);
	while (compt++ < 600)
		my_mlx_pixel_put2(win, i, compt, 0x808080);
}

int	ft_close_win(t_canvas *canvas)
{
	printf("Window closed\n");
	free(canvas->win->window2);
	free(canvas->win->mlx);
	free(canvas->win);
	destroy_canvas(canvas);
	exit (0);
	return (0);
}
