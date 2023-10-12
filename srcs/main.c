/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:58:12 by agengemb          #+#    #+#             */
/*   Updated: 2023/10/12 15:47:22 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	set_data(t_canvas *canvas)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	canvas->player = player;
	canvas->player->x = -1;
	canvas->player->y = -1;
	return (0);
}

int	main(int argc, char **argv)
{
	size_t		index_format;
	char		*format;
	t_canvas	*canvas;

	format = ".cub";
	if (argc != 2)
	{
		printf("Usage: ./cube3D YourMap.cub\n");
		return (1);
	}
	index_format = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(argv[1] + index_format, format, 4) != 0)
	{
		printf("Wrong format\n");
		return (2);
	}
	canvas = create_canvas(argv[1]);
	if (!canvas)
		return (0);
	mlx_key_hook(canvas->window, move_player, canvas);
	mlx_hook(canvas->window, 17, 0, ft_close_win, canvas);
	set_data(canvas);
	new_image(canvas);
	draw_map(canvas);
	mlx_loop(canvas->mlx);
	destroy_canvas(canvas);
	return (0);
}
