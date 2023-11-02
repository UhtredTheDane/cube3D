/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:37:20 by anmande           #+#    #+#             */
/*   Updated: 2023/11/02 17:25:36 by anmande          ###   ########.fr       */
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
	tempo_dir_x = canvas->player->plane_x;
	tempo_dir_y = canvas->player->plane_y;
	canvas->player->plane_x = tempo_dir_x * cos(angle) - tempo_dir_y * sin(angle);
	canvas->player->plane_y = tempo_dir_x * sin(angle) + tempo_dir_y * cos(angle);
}

int	dcolision(t_canvas *canvas)
{
	double	x;
	double	y;

	x = (canvas->player->x);
	y = (canvas->player->y);
	if (canvas->player->dir_y < 0 && x >= canvas->map->row_nb - 3.)
	{
		return (0);
	}	
	else if (canvas->player->dir_y > 0 && x <= 2.2)
		return (0);
	else if (canvas->player->dir_x > 0 && y >= canvas->map->line_nb - 3.)
	{
		return (0);
	}
	else if (canvas->player->dir_x < 0 && y <= 2.5)
		return (0);
	return (1);
}

int	acolision(t_canvas *canvas)
{
	size_t	x;
	size_t	y;

	x = (canvas->player->x);
	y = (canvas->player->y);
	if (canvas->player->dir_y < 0 && x <= 2.5)
	{
		return (0);
	}	
	else if (canvas->player->dir_y > 0 && x >= canvas->map->row_nb - 3)
		return (0);
	else if (canvas->player->dir_x > 0 && y <= 2.5)
	{
		return (0);
	}
	else if (canvas->player->dir_x < 0 && y >= canvas->map->line_nb - 3.)
		return (0);
	return (1);
}

int	scolision(t_canvas *canvas)
{
	double	x;
	double	y;

	x = canvas->player->x;
	y = canvas->player->y;
	if (canvas->player->dir_y > 0 && y <= 2.5)
	{
		return (0);
	}	
	else if (canvas->player->dir_y < 0 && y >= canvas->map->line_nb - 3.)
	{
		return (0);
	}
	if (canvas->player->dir_x > 0 && x <= 2.5)
	{
		return (0);
	}
	else if (canvas->player->dir_x < 0 && x >= canvas->map->row_nb - 3.)
		return (0);
	return (1);
}

int	wcolision(t_canvas *canvas)
{
	double	x;
	double	y;

	x = canvas->player->x;
	y = canvas->player->y;
	if (canvas->player->dir_y < 0 && canvas->player->y <= 2.2)
	{
		return (0);
	}	
	else if (canvas->player->dir_y > 0 && y >= canvas->map->line_nb - 2.5)
	{
		return (0);
	}
	if (canvas->player->dir_x < 0 && x <= 2.5)
	{
		return (0);
	}
	else if (canvas->player->dir_x > 0 && x >= canvas->map->row_nb - 2.5)
		return (0);
	return (1);
}
