/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:19:51 by anmande           #+#    #+#             */
/*   Updated: 2023/10/04 14:49:19 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"

void	my_mlx_pixel_put(t_canvas *canvas, int x, int y, int color)
{
	char	*distance;

	distance = canvas->addr + (y * canvas->width + x * (canvas->bits_per_pixel / 8));
    *(unsigned int*)distance = color;
}

void    draw_map(t_canvas *canvas)
{
    int i;
    int j;
    while (i < 10)
    {
        j = 0;
        while (j < 10)
        {
            //my_mlx_pixel_put(canvas->img, i, j, 0x00FF0000);
            j++;
        }
        i++;
    }
    (void)canvas;
    //mlx_put_image_to_window(canvas->mlx, canvas->window, canvas->img, 0, 0);
}
