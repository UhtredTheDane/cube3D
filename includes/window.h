/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:31:02 by anmande           #+#    #+#             */
/*   Updated: 2023/10/05 11:22:26 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H

# define WINDOW_H

# include "main.h"

//Cette fonction ne fait que fermer la fenetre rien de propre

int	    ft_close_win(long int key, t_canvas *canvas);
void    draw_map(t_canvas *canvas, int fd);
void	my_mlx_pixel_put(t_canvas *canvas, int x, int y, int color);


#endif