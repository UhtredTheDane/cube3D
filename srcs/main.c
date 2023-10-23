/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:58:12 by agengemb          #+#    #+#             */
/*   Updated: 2023/10/23 16:58:31 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

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
	canvas->player->w = 0;
	canvas->player->angle = 0;
	mlx_hook(canvas->window, 2, (1L << 0), move_player, canvas);
	mlx_hook(canvas->window, 17, 0, ft_close_win, canvas);
	new_image(canvas);
	move_player(0, canvas);
	mlx_loop(canvas->mlx);
	destroy_canvas(canvas);
	return (0);
}
