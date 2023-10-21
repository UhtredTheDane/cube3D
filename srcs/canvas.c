/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 23:04:12 by agengemb          #+#    #+#             */
/*   Updated: 2023/10/20 17:01:08 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/canvas.h"

void	destroy_canvas(t_canvas *canvas)
{
	destroy_map(canvas->mlx, canvas->map);
	mlx_destroy_window(canvas->mlx, canvas->window);
	mlx_destroy_display(canvas->mlx);
	free(canvas->mlx);
	free(canvas);
}

t_canvas	*create_canvas(char *file_name)
{
	t_canvas	*new_canvas;

	new_canvas = malloc(sizeof(t_canvas));
	if (!new_canvas)
		return (NULL);
	new_canvas->mlx = mlx_init();
	if (!new_canvas->mlx)
	{
		free(new_canvas);
		return (NULL);
	}
	new_canvas->player = malloc(sizeof(t_player));
	if (!new_canvas->player)
	{
		//free a faire
		return (NULL);
	}
	new_canvas->map = create_map(new_canvas->mlx, file_name);
	if (!new_canvas->map)
	{
		free(new_canvas->mlx);
		free(new_canvas);
		return (NULL);
	}
	new_canvas->window = mlx_new_window(new_canvas->mlx, new_canvas->map->row_nb *SQUARE, new_canvas->map->line_nb *SQUARE, "cube3D");
	if (!new_canvas->window)
	{
		destroy_map(new_canvas->mlx, new_canvas->map);
		free(new_canvas->mlx);
		free(new_canvas);
		return (NULL);
	}
	return (new_canvas);
}
