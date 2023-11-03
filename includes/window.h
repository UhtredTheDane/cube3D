/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:31:02 by anmande           #+#    #+#             */
/*   Updated: 2023/11/02 15:48:26 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H

# define WINDOW_H
# define WIDTH 800
# define HEIGHT 1000
# define FOV 6

# include "main.h"
# include "ray.h"
# include "canvas.h"

typedef struct s_canvas	t_canvas;
typedef struct s_win	t_win;

int		ft_close_win(t_canvas *canvas);
void	new_image(t_canvas *canvas);
void	draw_map(t_canvas *canvas);
void	my_mlx_pixel_put(t_canvas *canvas, int x, int y, int color);
void	draw_ray(t_canvas *canvas);
void	draw_squar(t_canvas *canvas, int color, int x_map, int y_map);
void	draw_player(t_canvas *canvas);
void	win_3d(t_canvas *canvas, t_ray *ray, int i);
t_win	*init_window(void *mlx);
double get_texX(t_canvas *canvas, t_ray *ray, double dm);
void	init_pos_player(t_canvas *canvas, size_t i, size_t j, char dir);
double	get_side_dist_x(t_ray *ray, double player_posx);
double	get_side_disty(t_ray *ray, double player_posY);
void	draw_ray(t_canvas *canvas);
double	get_wall_dist(t_map *map, t_ray *ray);

#endif
