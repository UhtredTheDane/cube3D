/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:19:51 by anmande           #+#    #+#             */
/*   Updated: 2023/10/05 11:26:35 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"

void	my_mlx_pixel_put(t_canvas *canvas, int x, int y, int color)
{
	char	*dst;

	dst = canvas->addr + (y * canvas->line_len + x * (canvas->bpp / 8));
	*(unsigned int *)dst = color;
}

void	new_image(t_canvas *canvas)
{
	canvas->img = mlx_new_image(canvas->mlx, X_LEN, Y_LEN);
	canvas->addr = mlx_get_data_addr(canvas->img, &canvas->bpp, &canvas->width, &canvas->height);
}

void	draw_squar(t_canvas *canvas, int color, int x_map, int y_map)
{
	int	i;
	int	j;

	i = x_map * 10;
	while (i < (x_map + 1) * 10)
	{
		j = y_map * 10;
		while (j < (y_map + 1) * 10)
		{
			my_mlx_pixel_put(canvas, i, j, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(canvas->mlx, canvas->window, canvas->img, 0, 0);
}


void	draw_map(t_canvas *canvas, int fd)
{
	int 	i;
	int 	j;
	char	*line;

	j = 0;
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		//printf("%s\n", line);
		while (line[i])
		{
			if (line[i] == '1')
				draw_squar(canvas, 0xFF0000, i, j);
			else if (line[i] == '0')
				draw_squar(canvas, 0x00FF00, i, j);
			else if (line[i] == ' ')
				draw_squar(canvas, 0x0000FF, i, j);
			i++;
		}
		line = get_next_line(fd);
		j++;
	}
}
