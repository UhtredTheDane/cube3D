/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:24:53 by anmande           #+#    #+#             */
/*   Updated: 2023/10/31 14:25:57 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"

void	draw_squar(t_canvas *canvas, int color, int x_map, int y_map)
{
	int	i;
	int	j;

	i = x_map *SQUARE;
	while (i < (x_map + 1) * SQUARE)
	{
		j = y_map * SQUARE;
		while (j < (y_map + 1) * SQUARE)
		{
			if (i == x_map * SQUARE || i == (x_map + 1) * SQUARE - 1 || j == y_map * SQUARE || j == (y_map + 1) *SQUARE - 1)
				my_mlx_pixel_put(canvas, j, i, 0x000000);
			else
			my_mlx_pixel_put(canvas, j, i, color);
			j++;
		}
		i++;
	}
	(void)color;
	(void)canvas;
}