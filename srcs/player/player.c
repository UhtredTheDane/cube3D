/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:37:20 by anmande           #+#    #+#             */
/*   Updated: 2023/10/12 16:24:42 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"
#include "../../includes/window.h"

int	move_player(int key, t_canvas *canvas)
{
    if (key == 65307)
	{
        mlx_loop_end(canvas->mlx);
		exit (0);
	}
    if (key == PRESS_ARROW_UP || key == PRESS_W)
    {
		canvas->player->y -= 5;
		printf("up\n");
    }
    if (key == PRESS_ARROW_DOWN || key == PRESS_S)
    {
        canvas->player->y += 5;
		printf("down\n");
    }
    if (key == PRESS_ARROW_LEFT || key == PRESS_A)
    {
        canvas->player->x -= 5;
		printf("left\n");
    }
    if (key == PRESS_ARROW_RIGHT || key == PRESS_D)
    {
        canvas->player->x += 5;
		printf("right\n");
    }
    draw_map(canvas);
    //(void)canvas;
    return (0);
}