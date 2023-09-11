/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 23:24:25 by agengemb          #+#    #+#             */
/*   Updated: 2023/09/11 20:07:44 by agengemb         ###   ########.fr       */
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

typedef struct s_map	t_map;

char	**switch_face(t_map *map, char **face, int num_face);
t_list	*loading_map(int map_fd, size_t *row_nb);
int	loading_texture(char **map_face, char *line, char *face);
int run_loading_texture(t_map *map, int num_face, int map_fd);

int create_trgb(int t, int r, int g, int b);
int get_value(char **line, char symbol);
int loading_color(t_map *map, char *type, int map_fd);

char	*create_wrapper(size_t row_nb);
void	add_wrappers(t_list **lst, size_t row_nb);
t_list *load_line(t_list **lst, char *line, size_t *row_nb);
t_list	*loading_map(int map_fd, size_t *row_nb);

char *trim_backspace(int map_fd);
char *trim_space(char *line, int shifting);

int get_textures(t_map *map, int map_fd);
int get_colors(t_map *map, int map_fd);
t_list *get_map(t_map *map, int map_fd);
t_list *loading_file(t_map *map, char *file_name);

#endif
