/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:37:20 by anmande           #+#    #+#             */
/*   Updated: 2023/10/23 16:25:24 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"
#include "../../includes/window.h"
#include <math.h>
#include <X11/keysym.h>
#define PI 3.14159265359

void rotate_player(t_canvas *canvas, double angle)
{
	double tempo_dir_x;
	double tempo_dir_y;
	
	tempo_dir_x = canvas->player->dir_x;
	tempo_dir_y = canvas->player->dir_y;
	canvas->player->angle += angle;
	canvas->player->dir_x = tempo_dir_x * cos(angle) - tempo_dir_y * sin(angle);
	canvas->player->dir_y = tempo_dir_x * sin(angle) + tempo_dir_y * cos(angle);
}

int	move_player(int key, t_canvas *canvas)
{
	if (key == 65307)
	{
		mlx_loop_end(canvas->mlx);
		exit (0);
	}
	if (key == PRESS_W || key == PRESS_ARROW_UP)
	{
		canvas->player->y += canvas->player->dir_y * 2.0;
		canvas->player->x += canvas->player->dir_x * 2.0;
	}
	if (key == PRESS_S || key == PRESS_ARROW_DOWN)
	{	
		canvas->player->y -= canvas->player->dir_y * 2.0;
		canvas->player->x -= canvas->player->dir_x * 2.0;
	}
	if (key == PRESS_A || key == PRESS_ARROW_LEFT)
	{
		canvas->player->y -= canvas->player->dir_x * 2.0;
		canvas->player->x += canvas->player->dir_y * 2.0;
	}
	if (key == PRESS_D || key == PRESS_ARROW_RIGHT)
	{
		canvas->player->y += canvas->player->dir_x * 2.0;
		canvas->player->x -= canvas->player->dir_y * 2.0;
	}
	if (key == XK_q)
		rotate_player(canvas, PI / -16);
	if (key == XK_e)
		rotate_player(canvas, PI / 16);
	draw_map(canvas);
	return (0);
}
