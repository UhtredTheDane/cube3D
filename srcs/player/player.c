/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:37:20 by anmande           #+#    #+#             */
/*   Updated: 2023/10/31 18:55:33 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"
#include "../../includes/window.h"
#include <math.h>
#include <X11/keysym.h>
#define PI 3.14159265359

void	rotate_player(t_canvas *canvas, double angle)
{
	double	tempo_dir_x;
	double	tempo_dir_y;

	tempo_dir_x = canvas->player->dir_x;
	tempo_dir_y = canvas->player->dir_y;
	canvas->player->dir_x = tempo_dir_x * cos(angle) - tempo_dir_y * sin(angle);
	canvas->player->dir_y = tempo_dir_x * sin(angle) + tempo_dir_y * cos(angle);
}

int	dcolision(t_canvas *canvas)
{
	size_t	x;
	size_t	y;

	x = (canvas->player->x) / SQUARE;
	y = (canvas->player->y) / SQUARE;
	if (canvas->player->dir_y < 0 && x >= canvas->map->row_nb - 2)
	{
		return (0);
	}	
	else if (canvas->player->dir_y > 0 && x <= 1)
		return (0);
	else if (canvas->player->dir_x > 0 && y >= canvas->map->line_nb - 2)
	{
		return (0);
	}
	else if (canvas->player->dir_x < 0 && y <= 1)
		return (0);

	return (1);
}

int	acolision(t_canvas *canvas)
{
	size_t	x;
	size_t	y;

	x = (canvas->player->x) / SQUARE;
	y = (canvas->player->y) / SQUARE;
	if (canvas->player->dir_y < 0 && x <= 1)
	{
		return (0);
	}	
	else if (canvas->player->dir_y > 0 && x >= canvas->map->row_nb - 2)
		return (0);
	else if (canvas->player->dir_x > 0 && y <= 1)
	{
		return (0);
	}
	else if (canvas->player->dir_x < 0 && y >= canvas->map->line_nb - 2)
		return (0);
	return (1);
}

int	scolision(t_canvas *canvas)
{
	size_t	x;
	size_t	y;

	x = canvas->player->x / SQUARE;
	y = canvas->player->y / SQUARE;
	if (canvas->player->dir_y > 0 && y <= 1)
	{
		return (0);
	}	
	else if (canvas->player->dir_y < 0 && y >= canvas->map->line_nb - 2)
	{
		return (0);
	}
	if (canvas->player->dir_x > 0 && x <= 1)
	{
		return (0);
	}
	else if (canvas->player->dir_x < 0 && x >= canvas->map->row_nb - 2)
		return (0);
	return (1);
}

int	wcolision(t_canvas *canvas)
{
	double	x;
	double	y;

	x = canvas->player->x / SQUARE;
	y = canvas->player->y / SQUARE;
	if (canvas->player->dir_y < 0 && y <= 1)
	{
		return (0);
	}	
	else if (canvas->player->dir_y > 0 && y >= canvas->map->line_nb - 2)
	{
		return (0);
	}
	if (canvas->player->dir_x < 0 && x <= 1)
	{
		return (0);
	}
	else if (canvas->player->dir_x > 0 && x >= canvas->map->row_nb - 2)
		return (0);
	return (1);
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
	if ((key == PRESS_A || key == PRESS_ARROW_LEFT) && acolision(canvas) == 1)
		move_left(canvas);
	if ((key == PRESS_D || key == PRESS_ARROW_RIGHT) && dcolision(canvas) == 1)
		move_right(canvas);
	if (key == XK_q)
		rotate_player(canvas, PI / -16);
	if (key == XK_e)
		rotate_player(canvas, PI / 16);
	draw_map(canvas);
	return (0);
}
