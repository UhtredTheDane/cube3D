/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:29:19 by anmande           #+#    #+#             */
/*   Updated: 2023/10/04 14:31:39 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"

int	ft_close_win(long int key, t_canvas *canvas)
{
	if (key == 65307 || key == 17)
	{
        mlx_loop_end(canvas->mlx);
		destroy_canvas(canvas);
		free(canvas->mlx);
		exit (0);
	}
	return (0);
}
