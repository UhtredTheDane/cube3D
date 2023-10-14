/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:37:20 by anmande           #+#    #+#             */
/*   Updated: 2023/10/14 18:30:59 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"
#include "../../includes/window.h"
#include <math.h>
#include <X11/keysym.h>
#define PI 3.14159265359

int	move_player(int key, t_canvas *canvas)
{
	if (key == 65307)
	{
		mlx_loop_end(canvas->mlx);
		exit (0);
	}
	if (key == PRESS_W)
	{
		canvas->player->y += canvas->player->dir_y * 5;
    		canvas->player->x += canvas->player->dir_x * 5;
    }
    if (key == PRESS_S)
	{	
		canvas->player->y -= canvas->player->dir_y * 5;
    		canvas->player->x -= canvas->player->dir_x * 5;
	}
    if (key == PRESS_A)
    {
	    canvas->player->y -= canvas->player->dir_x * 5;
    	canvas->player->x += canvas->player->dir_y * 5;

    }
    if (key == PRESS_D)
    {
	    canvas->player->y += canvas->player->dir_x * 5;
    		canvas->player->x -= canvas->player->dir_y * 5;
    }
    if (key == XK_q)
    {
	double tempo_dir_x = canvas->player->dir_x;
	double tempo_dir_y = canvas->player->dir_y;
	canvas->player->dir_x = tempo_dir_x * cos(PI / -4) - tempo_dir_y * sin(PI / -4);
	canvas->player->dir_y = tempo_dir_x * sin(PI / -4) + tempo_dir_y * cos(PI / -4);
    }
    if (key == XK_e)
    {
	double tempo_dir_x = canvas->player->dir_x;
	double tempo_dir_y = canvas->player->dir_y;
	canvas->player->dir_x = tempo_dir_x * cos(PI / 4) - tempo_dir_y * sin(PI / 4);
	canvas->player->dir_y = tempo_dir_x * sin(PI / 4) + tempo_dir_y * cos(PI / 4);
    }
    draw_map(canvas);
    return (0);
}
