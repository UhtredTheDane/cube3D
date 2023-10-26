/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:37:20 by anmande           #+#    #+#             */
/*   Updated: 2023/10/26 18:50:30 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"
#include "../../includes/window.h"
#include <math.h>
#include <X11/keysym.h>
#define PI 3.14159265359

void rotate_player(t_canvas *canvas, double angle)
{
	double	tempo_dir_x;
	double	tempo_dir_y;

	tempo_dir_x = canvas->player->dir_x;
	tempo_dir_y = canvas->player->dir_y;
	canvas->player->dir_x = tempo_dir_x * cos(angle) - tempo_dir_y * sin(angle);
	canvas->player->dir_y = tempo_dir_x * sin(angle) + tempo_dir_y * cos(angle);
}

int	d_collision(t_canvas *canvas)
{
	size_t	x;
	size_t	y;
	size_t	i;

	i = canvas->map->row_nb - 2;
	x = (canvas->player->x) / SQUARE;
	y = (canvas->player->y) / SQUARE;
		if (canvas->player->dir_y >= 0)
	{
		if (y <= 1)
			return (0);
	}	
	else if (canvas->player->dir_y < 0)
		if (y >= i)
			return (0);
	if (canvas->player->dir_x >= 0)
	{
		if (x <= 1)
			return (0);
	}
	else if (canvas->player->dir_x < 0)
		if (x >= i)
			return (0);
	return (1);
}

int	a_collision(t_canvas *canvas)
{
	size_t	x;
	size_t	y;
	size_t	i;

	i = canvas->map->row_nb - 2;
	x = (canvas->player->x) / SQUARE;
	y = (canvas->player->y) / SQUARE;
	if (canvas->player->dir_y < 0)
	{
		if (x <= 1)
			return (0);
	}	
	else if (canvas->player->dir_y > 0)
	{
		if (x >= i)
			return (0);
	}
	if (canvas->player->dir_x > 0)
	{
		if (y <= 1)
			return (0);
	}
	else if (canvas->player->dir_x < 0)
		if (y >= i)
			return (0);
	return (1);
}

int	s_collision(t_canvas *canvas)
{
	size_t	x;
	size_t	y;
	size_t	i;

	i = canvas->map->row_nb - 2;
	x = (canvas->player->x) / SQUARE;
	y = (canvas->player->y) / SQUARE;
	if (canvas->player->dir_y > 0)
	{
		if (y <= 1)
			return (0);
	}	
	else if (canvas->player->dir_y < 0)
		if (y >= i)
			return (0);
	if (canvas->player->dir_x > 0)
	{
		if (x <= 1)
			return (0);
	}
	else if (canvas->player->dir_x < 0)
		if (x >= i)
			return (0);
	return (1);
}

int	player_collision(t_canvas *canvas)
{
	size_t	x;
	size_t	y;
	size_t	i;

	i = canvas->map->line_nb - 2;
	x = (canvas->player->x) / SQUARE;
	y = (canvas->player->y) / SQUARE;
	if (canvas->player->dir_y < 0)
	{
		if (y <= 1)
			return (0);
	}	
	else if (canvas->player->dir_y > 0)
		if (y >= i)
			return (0);
	if (canvas->player->dir_x < 0)
	{
		if (x <= 1)
			return (0);
	}
	else if (canvas->player->dir_x > 0)
		if (x >= i)
			return (0);
	return (1);
}

int	move_player(int key, t_canvas *canvas)
{
	if (key == 65307)
	{
		mlx_loop_end(canvas->mlx);
		destroy_canvas(canvas);
		exit (0);
	}
	if ((key == PRESS_W || key == PRESS_ARROW_UP) && player_collision(canvas) == 1)
	{
		if (canvas->player->y > 0)
			canvas->player->y += canvas->player->dir_y * 2.0;
		if (canvas->player->x > 0)
			canvas->player->x += canvas->player->dir_x * 2.0;
	}
	if ((key == PRESS_S || key == PRESS_ARROW_DOWN) && s_collision(canvas) == 1)
	{	
		if (canvas->player->y < canvas->map->line_nb * 30)
			canvas->player->y -= canvas->player->dir_y * 2.0;
		if (canvas->player->x < canvas->map->row_nb * 30)
			canvas->player->x -= canvas->player->dir_x * 2.0;
	}
	if ((key == PRESS_A || key == PRESS_ARROW_LEFT) && a_collision(canvas) == 1)
	{
		if (canvas->player->y < canvas->map->line_nb * 30)
			canvas->player->y -= canvas->player->dir_x * 2.0;
		if (canvas->player->x > 0)
			canvas->player->x += canvas->player->dir_y * 2.0;
	}
	if ((key == PRESS_D || key == PRESS_ARROW_RIGHT) && d_collision(canvas) == 1)
	{
		if (canvas->player->y > 0)
			canvas->player->y += canvas->player->dir_x * 2.0;
		if (canvas->player->x < canvas->map->row_nb * 30)
			canvas->player->x -= canvas->player->dir_y * 2.0;
	}
	if (key == XK_q)
		rotate_player(canvas, PI / -16);
	if (key == XK_e)
		rotate_player(canvas, PI / 16);
	draw_map(canvas);
	return (0);
}
