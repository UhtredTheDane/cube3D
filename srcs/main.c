/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:58:12 by agengemb          #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2023/09/08 21:08:52 by agengemb         ###   ########.fr       */
=======
/*   Updated: 2023/10/04 16:09:58 by anmande          ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	set_data(t_canvas *canvas)
{
	canvas->mlx = mlx_init();
	canvas->window = mlx_new_window(canvas->mlx, 1000, 1000, "cub3D");
	canvas->img = mlx_new_image(canvas->mlx, 1000, 1000);
	canvas->addr = mlx_get_data_addr(canvas->img, &canvas->bits_per_pixel,
			&canvas->line_length, &canvas->endian);
}

int main(int argc, char **argv)
{
<<<<<<< Updated upstream
	size_t	index_format;
	char	*format;
	t_canvas *canvas;
=======
	//size_t		index_format;
	//char		*format;
	t_canvas	canvas;
>>>>>>> Stashed changes

	// format = ".cub";
	if (argc != 2)
	{
		printf("Usage: ./cube3D YourMap.cub\n");
		return (1);
	}
<<<<<<< Updated upstream
	index_format = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(argv[1] + index_format, format, 4) != 0)
	{
		printf("Wrong format\n");
		return (2);
	}
	canvas = create_canvas(argv[1]);
 	if (!canvas)
		return (0);
	destroy_canvas(canvas);
=======
	// index_format = ft_strlen(argv[1]) - 4;
	// if (ft_strncmp(argv[1] + index_format, format, 4) != 0)
	// {
	// 	printf("Wrong format\n");
	// 	return (2);
	// }
	// canvas = create_canvas(argv[1]);
 	// if (!canvas)
	// 	return (0);
	//canvas->color = 250;
	set_data(&canvas);
	// mlx_hook(canvas.window, 17, 0, ft_close_win, &canvas);
	// mlx_hook(canvas.window, 2, 1L << 0, ft_close_win, &canvas);
	// draw_map(&canvas);
	// mlx_loop(canvas.mlx);
	// destroy_canvas(&canvas);
	(void)argv;
>>>>>>> Stashed changes
	return (0);
} 
