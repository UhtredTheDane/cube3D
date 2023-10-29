/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:39:39 by anmande           #+#    #+#             */
/*   Updated: 2023/10/27 14:14:04 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H

# define PLAYER_H

#include "main.h"
#include "window.h"

# define PRESS_ARROW_UP 65362
# define PRESS_ARROW_DOWN 65364
# define PRESS_ARROW_LEFT 65361
# define PRESS_ARROW_RIGHT 65363
# define PRESS_W 119
# define PRESS_S 115
# define PRESS_A 97
# define PRESS_D 100
# define SQUARE 30

typedef struct s_canvas t_canvas;
typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		w;
	int		a;
	int		s;
	int		d;
	int		q;
	int		e;
}		t_player;

int		move_player(int key, t_canvas *canvas);
void	move_up(t_canvas *canvas);
void	move_down(t_canvas *canvas);
void	move_left(t_canvas *canvas);
void	move_right(t_canvas *canvas);

#endif
