/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:15:42 by agengemb          #+#    #+#             */
/*   Updated: 2023/09/08 00:23:20 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../../get_next_line/get_next_line.h"
# include "../../libft/libft.h"
# include "map.h"
# include "../block.h"
# include "loading.h"

typedef struct s_map	t_map;


int check_block(void *mlx, t_map *map, char symbol);
int check_path(t_map *map, t_block **block_map, int i_start, int j_start);
void rec_fill(t_map *map, t_block **block_map, int i, int j);
int check_remaining(t_map *map, t_block **copy_map, size_t i, size_t j);
int check_map(t_map *map, t_block **block_map, int i_start, int j_start);
t_block **copy(t_map *map, t_block **block_map);

#endif
