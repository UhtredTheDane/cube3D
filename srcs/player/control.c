/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:33:56 by anmande           #+#    #+#             */
/*   Updated: 2023/11/03 16:56:52 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"
#include <math.h>
#include <X11/keysym.h>

void	move_up(t_canvas *canvas)
{
	canvas->player->y += canvas->player->dir_y * 0.1;
	canvas->player->x += canvas->player->dir_x * 0.1;
}

void	move_down(t_canvas *canvas)
{
		canvas->player->y -= canvas->player->dir_y * 0.1;
		canvas->player->x -= canvas->player->dir_x * 0.1;
}

void	move_left(t_canvas *canvas)
{
		canvas->player->y -= canvas->player->dir_x * 0.1;
		canvas->player->x += canvas->player->dir_y * 0.1;
}

void	move_right(t_canvas *canvas)
{
		canvas->player->y += canvas->player->dir_x * 0.1;
		canvas->player->x -= canvas->player->dir_y * 0.1;
}

int	move_player(int key, t_canvas *canvas)
{
	if (key == 65307)
	{
		ft_close_win(canvas);
		mlx_loop_end(canvas->mlx);
		exit (0);
	}
	if ((key == PRESS_W || key == PRESS_ARROW_UP) && wcolision(canvas) == 1)
		move_up(canvas);
	if ((key == PRESS_S || key == PRESS_ARROW_DOWN) && scolision(canvas) == 1)
		move_down(canvas);
	if ((key == PRESS_A) && acolision(canvas) == 1)
		move_left(canvas);
	if ((key == PRESS_D) && dcolision(canvas) == 1)
		move_right(canvas);
	if (key == XK_q || key == PRESS_ARROW_LEFT)
		rotate_player(canvas, M_PI / -16);
	if (key == XK_e || key == PRESS_ARROW_RIGHT)
		rotate_player(canvas, M_PI / 16);
	draw_ray(canvas);
	return (0);
}
