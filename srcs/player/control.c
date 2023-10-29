/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:33:56 by anmande           #+#    #+#             */
/*   Updated: 2023/10/27 13:38:47 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"

void	move_up(t_canvas *canvas)
{
	//if (canvas->player->y > 0)
		canvas->player->y += canvas->player->dir_y * 5.0;
	//if (canvas->player->x > 0)
		canvas->player->x += canvas->player->dir_x * 5.0;
}

void	move_down(t_canvas *canvas)
{
	//if (canvas->player->y < canvas->map->line_nb * SQUARE)
		canvas->player->y -= canvas->player->dir_y * 5.0;
	//if (canvas->player->x < canvas->map->row_nb * SQUARE)
		canvas->player->x -= canvas->player->dir_x * 5.0;
}

void	move_left(t_canvas *canvas)
{
	//if (canvas->player->y < canvas->map->line_nb * SQUARE)
		canvas->player->y -= canvas->player->dir_x * 5.0;
	//if (canvas->player->x > 0)
		canvas->player->x += canvas->player->dir_y * 5.0;
}

void	move_right(t_canvas *canvas)
{
	//if (canvas->player->y > 0)
		canvas->player->y += canvas->player->dir_x * 5.0;
	//if (canvas->player->x < canvas->map->row_nb * SQUARE)
		canvas->player->x -= canvas->player->dir_y * 5.0;
}
