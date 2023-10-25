/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:29:19 by anmande           #+#    #+#             */
/*   Updated: 2023/10/23 18:38:09 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"

void	my_mlx_pixel_put2(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->line_len + x * (win->bpp / 8));
	*(unsigned int *)dst = color;
}

t_win	*init_window(void)
{
	t_win	*win;

	win = malloc(sizeof(t_win));
	if (!win)
		return (NULL);
	win->mlx = mlx_init();
	win->window2 = mlx_new_window(win->mlx, 800, 600, "cub3D");
	win->img = mlx_new_image(win->mlx, 800, 600);
	win->addr = mlx_get_data_addr(win->img, &win->bpp, &win->line_len, &win->endian);
	return (win);
}

void	win_3d(double dist, t_win *win, int i)
{
	// int	j;

	// j = 0;
	// while (j < 20)
	// {
	// 	my_mlx_pixel_put2(win, 0, 0, 0x05500);
	// 	j++;
	// }
	//my_mlx_pixel_put2(win, i, 0, 0x000000);
	printf ("ray %d de taille %f\n", i, dist);
	//mlx_put_image_to_window(win->mlx, win->window2, win->img, 0, 0);
	(void)win;
}

int	ft_close_win(t_canvas *canvas)
{

	exit (0);
	(void)canvas;
}
