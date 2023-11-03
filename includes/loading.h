/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 23:24:25 by agengemb          #+#    #+#             */
/*   Updated: 2023/11/03 14:43:31 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOADING_H
# define LOADING_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "map/map.h"
# include "img.h"

typedef struct s_map	t_map;
typedef struct s_img	t_img;

t_img	**switch_face(t_map *map, char **face, int num_face);
t_list	*loading_map(int map_fd, size_t *row_nb);
int	loading_texture(void *mlx, t_img **map_face, char *line);
int run_loading_texture(void *mlx, t_map *map, char *line, int num_face);

int create_trgb(int t, int r, int g, int b);
int get_value(char **line, char symbol);
int loading_color(t_map *map, char *line, char type);

char	*create_wrapper(size_t row_nb);
void	add_wrappers(t_list **lst, size_t row_nb);
t_list *load_line(t_list **lst, char *line, size_t *row_nb);
t_list	*loading_map(int map_fd, size_t *row_nb);

char *trim_backspace(int map_fd);
char *trim_space(char *line, int shifting);
void empty_buffer(int map_fd);

int get_textures(void *mlx, t_map *map, int map_fd);
int get_colors(t_map *map, int map_fd);
t_list *get_map(t_map *map, int map_fd);
t_list *loading_file(void *mlx, t_map *map, char *file_name);

#endif
