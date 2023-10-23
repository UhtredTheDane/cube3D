/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:29:19 by anmande           #+#    #+#             */
/*   Updated: 2023/10/23 17:09:46 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"

void	win_3d(double dist, t_canvas *canvas, int i)
{
	my_mlx_pixel_put(canvas, i, 0, 0x000000);
	printf ("ray %d de taille %f\n", i, dist);
	(void)canvas;
}

int	ft_close_win(t_canvas *canvas)
{

	exit (0);
	(void)canvas;
}
