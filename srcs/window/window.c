/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:29:19 by anmande           #+#    #+#             */
/*   Updated: 2023/10/04 14:55:34 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"

int	ft_close_win(long int key, t_canvas *canvas)
{
	if (key == 65307 || key == 17)
	{
        mlx_loop_end(canvas->mlx);
		// if (canvas->img)
		// 	mlx_destroy_image(canvas->mlx, canvas->img);
		//mlx_destroy_window(canvas->mlx, canvas->window);
		//mlx_destroy_display(canvas->mlx);
		//free(canvas->mlx);
		//destroy_canvas(canvas);
        exit (0);
	}
	return (0);
}
