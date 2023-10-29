/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:20:03 by anmande           #+#    #+#             */
/*   Updated: 2023/10/27 16:27:38 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"

void	detect_block_type(t_canvas *canvas, size_t i, size_t j)
{
	char	block_type;

	block_type = canvas->map->block_map[i][j].type;
	if (block_type == '1')
		draw_squar(canvas, 0xFF0000, i, j);
	else if (block_type == '0' || block_type == ' ')
		draw_squar(canvas, 0x808080, i, j);
	else if (block_type == 'N')
		init_pos_player(canvas, i, j, 'N');
	else if (block_type == 'S')
		init_pos_player(canvas, i, j, 'S');
	else if (block_type == 'E')
		init_pos_player(canvas, i, j, 'E');
	else if (block_type == 'W')
		init_pos_player(canvas, i, j, 'W');
}

void	init_pos_player(t_canvas *canvas, size_t i, size_t j, char dir)
{
	canvas->map->block_map[i][j].type = '0';
	draw_squar(canvas, 0x808080, i, j);
	canvas->player->x = j * SQUARE + 15;
	canvas->player->y = i * SQUARE + 15;
	if (dir == 'N')
	{
		canvas->player->dir_x = 0;
		canvas->player->dir_y = -1;
	}
	else if (dir == 'S')
	{
		canvas->player->dir_x = 0;
		canvas->player->dir_y = 1;
	}
	else if (dir == 'E')
	{
		canvas->player->dir_x = 1;
		canvas->player->dir_y = 0;
	}
	else
	{
		canvas->player->dir_x = -1.;
		canvas->player->dir_y = 0.;
	}
}

double	get_side_dist_x(t_ray *ray, double player_posx)
{
	double	sidedist_x;
	int		num_row;

	num_row = trunc(player_posx / SQUARE);
	if (ray->dir_x < 0)
	{
		ray->stepx = -1;
		sidedist_x = (player_posx - num_row * SQUARE) * ray->deltadist_x;
	}
	else
	{
		ray->stepx = 1;
		sidedist_x = ((num_row + 1) * SQUARE - player_posx) * ray->deltadist_x;
	}
	return (sidedist_x);
}

double	get_side_disty(t_ray *ray, double player_posY)
{
	double	sidedisty;
	int		num_line;

	num_line = trunc(player_posY / SQUARE);
	if (ray->dir_y < 0)
	{
		ray->stepY = -1;
		sidedisty = (player_posY - num_line * SQUARE) * ray->deltadisty;
	}
	else
	{
		ray->stepY = 1;
		sidedisty = ((num_line + 1) * SQUARE - player_posY) * ray->deltadisty;
	}
	return (sidedisty);
}
