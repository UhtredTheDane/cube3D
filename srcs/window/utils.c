/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:05:42 by agengemb          #+#    #+#             */
/*   Updated: 2023/10/29 14:05:47 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"

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
