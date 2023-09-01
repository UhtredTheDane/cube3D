/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:15:42 by agengemb          #+#    #+#             */
/*   Updated: 2023/08/31 18:02:14 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "queue.h"
# include "map.h"
# include "block.h"

typedef struct s_map	t_map;

t_queue *load_map_in_queue(int map_fd, size_t *row_nb);
t_queue *read_map(char *file_name, size_t *row_nb);
t_map *init_map(size_t line_nb, size_t row_nb);
int create_2D_tab(t_map *map, t_block **block_map);
int check_block(void *mlx, t_map *map, char symbol);
void init_block(t_block *block, char symbol);
int fill_map(void *mlx, t_map *map, t_block **block_map, t_queue *queue);
int check_path(t_map *map, t_block **block_map, int i_start, int j_start);
void rec_fill(t_block **block_map, int i, int j);
int check_remaining(t_map *map, t_block **copy_map, size_t i, size_t j);
int check_map(t_map *map, t_block **block_map, int i_start, int j_start);
int init_block_map(void *mlx, t_map *map, t_queue *queue);
t_map *create_map(void *mlx, t_queue *queue, size_t line_nb, size_t row_nb);
t_block **copy(t_map *map, t_block **block_map);
t_queue	*load_map_in_queue(int map_fd, size_t *row_nb);

#endif
