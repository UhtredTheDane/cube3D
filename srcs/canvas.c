/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:04:56 by agengemb          #+#    #+#             */
/*   Updated: 2023/11/03 17:06:10 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/canvas.h"

void	destroy_canvas(t_canvas *canvas)
{
	destroy_map(canvas->mlx, canvas->map);
	mlx_destroy_image(canvas->mlx, canvas->data.img);
	mlx_destroy_window(canvas->mlx, canvas->window);
	mlx_destroy_display(canvas->mlx);
	free(canvas->player);
	free(canvas->mlx);
	free(canvas);
}

void	new_image(t_canvas *canvas)
{
	canvas->data.img = mlx_new_image(canvas->mlx, 800, 600);
	canvas->data.addr = mlx_get_data_addr(canvas->data.img, &canvas->data.bpp, \
	&canvas->data.linlgth, &canvas->data.end);
}

t_canvas	*create_canvas(char *file_name)
{
	t_canvas	*new_canvas;

	new_canvas = malloc(sizeof(t_canvas));
	if (!new_canvas)
		return (NULL);
	new_canvas->mlx = mlx_init();
	if (!new_canvas->mlx)
		return (free(new_canvas), NULL);
	new_canvas->player = malloc(sizeof(t_player));
	if (!new_canvas->player)
		return (free(new_canvas->mlx), free(new_canvas), NULL);
	new_canvas->map = create_map(new_canvas, file_name);
	if (!new_canvas->map)
		return (free(new_canvas->player), mlx_destroy_display(new_canvas->mlx), \
		free(new_canvas->mlx), free(new_canvas), NULL);
	new_canvas->window = mlx_new_window(new_canvas->mlx, 800, 600, "cub3D");
	if (!new_canvas->window)
	{
		destroy_map(new_canvas->mlx, new_canvas->map);
		return (free(new_canvas->player), mlx_destroy_display(new_canvas->mlx), \
		free(new_canvas->mlx), free(new_canvas), NULL);
	}
	new_image(new_canvas);
	return (new_canvas);
}
