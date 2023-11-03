/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 00:24:19 by agengemb          #+#    #+#             */
/*   Updated: 2023/11/03 18:17:57 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "../../includes/map/map.h"

void	destroy_map(void *mlx, t_map *map)
{
	if (map->block_map)
		free_block_map(map->block_map, map->line_nb);
	if (map->no_path)
		free_img(mlx, map->no_path);
	if (map->so_path)
		free_img(mlx, map->so_path);
	if (map->we_path)
		free_img(mlx, map->we_path);
	if (map->ea_path)
		free_img(mlx, map->ea_path);
	free(map);
}

t_map	*init_map(void)
{
	t_map	*new_map;

	new_map = malloc(sizeof(t_map));
	if (!new_map)
		return (NULL);
	new_map->block_map = NULL;
	new_map->line_nb = 0;
	new_map->row_nb = 0;
	new_map->player = 0;
	new_map->no_path = NULL;
	new_map->so_path = NULL;
	new_map->we_path = NULL;
	new_map->ea_path = NULL;
	return (new_map);
}

void	detect_block_type(t_canvas *canvas, \
t_block **block_map, size_t i, size_t j)
{
	char	block_type;

	block_type = block_map[i][j].type;
	if (block_type == 'N')
		init_pos_player(canvas, i, j, 'N');
	else if (block_type == 'S')
		init_pos_player(canvas, i, j, 'S');
	else if (block_type == 'E')
		init_pos_player(canvas, i, j, 'E');
	else if (block_type == 'W')
		init_pos_player(canvas, i, j, 'W');
}

int	fill_map(t_canvas *canvas, t_map *map, t_block **block_map, t_list **list)
{
	char	*line;
	size_t	pos[2];

	pos[0] = 0;
	while (pos[0] < map->line_nb)
	{
		line = (*list)->content;
		pos[1] = 0;
		while (pos[1] < map->row_nb)
		{
			if (pos[1] < ft_strlen(line))
			{
				if (!check_block(canvas->mlx, map, line[pos[1]]))
					return (ft_lstclear(list, free), 0);
				init_block(&block_map[pos[0]][pos[1]], line[pos[1]]);
				detect_block_type(canvas, block_map, pos[0], pos[1]);
			}
			else
				init_block(&block_map[pos[0]][pos[1]], ' ');
			++pos[1];
		}
		ft_lstpop(list);
		++pos[0];
	}
	return (1);
}
