/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:33:39 by anmande           #+#    #+#             */
/*   Updated: 2023/10/27 16:33:46 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H

# define CANVAS_H
# define Y_LEN		1200
# define X_LEN		(Y_LEN)

# include <stdlib.h>
# include <stddef.h>
# include <math.h>

# include "../mlx_linux/mlx.h"
# include "map/map.h"
# include "../libft/libft.h"
# include "map/checking.h"
# include "player.h"
# include "data.h"

typedef struct s_map	t_map;
typedef struct s_player	t_player;
typedef struct s_win	t_win;

typedef struct s_canvas
{
	void		*mlx;
	void		*window;
	t_data		data;
	t_map		*map;
	int			fd;
	double		dist;
	t_player	*player;
	t_win		*win;
}			t_canvas;

typedef struct s_win
{
	void		*window2;
	void		*mlx;
	void		*img;
	char		*addr;
	t_canvas	*canvas;
	int			endian;
	int			line_len;
	int			bpp;
}	t_win;

t_canvas	*create_canvas(char *file_name);
void		destroy_canvas(t_canvas *canvas);
#endif
