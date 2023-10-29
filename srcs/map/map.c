/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 00:24:19 by agengemb          #+#    #+#             */
/*   Updated: 2023/10/04 14:39:44 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/map/map.h"

void destroy_map(void *mlx, t_map *map)
{
	if (map->block_map)
		free_block_map(map->block_map, map->line_nb);
	if (map->NO_path)
		free_img(mlx, map->NO_path);
	if (map->SO_path)
		free_img(mlx, map->SO_path);
	if (map->WE_path)
		free_img(mlx, map->WE_path);
	if (map->EA_path)
		free_img(mlx, map->EA_path);
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
	new_map->NO_path = NULL;
	new_map->SO_path = NULL;
	new_map->WE_path = NULL;
	new_map->EA_path = NULL;
	return (new_map);
}

void	detect_block_type(t_canvas *canvas, t_block **block_map, size_t i, size_t j)
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

void	init_pos_player(t_canvas *canvas, size_t i, size_t j, char dir)
{
	canvas->player->x = j + 0.5;
	canvas->player->y = i  + 0.5;
	if (dir == 'N')
	{
		canvas->player->dir_x = 0;
		canvas->player->dir_y = -1;
	}
	else if (dir == 'S')
	{
		canvas->player->dir_x = 0;
		canvas->player->dir_y = 1;
	}
	else if (dir == 'E')
	{
		canvas->player->dir_x = 1;
		canvas->player->dir_y = 0;
	}
	else
	{
		canvas->player->dir_x = -1.;
		canvas->player->dir_y = 0.;
	}
}

int	fill_map(t_canvas *canvas, t_map *map, t_block **block_map, t_list **list)
{
	char	*line;
	size_t	pos[2];
	size_t size_line;

	pos[0] = 0;
	while (pos[0] < map->line_nb)
	{
		line = (*list)->content;
		size_line = ft_strlen(line);
		pos[1] = 0;
		while (pos[1] < map->row_nb)
		{
			if (pos[1] < size_line)
			{
				if (!check_block(canvas->mlx, map, line[pos[1]]))
				{
					ft_lstclear(list, free);
					return (0);
				}
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

int	create_2d_tab(t_map *map, t_block **block_map)
{
	size_t	i;

	i = 0;
	while (i < map->line_nb)
	{
		block_map[i] = malloc(sizeof(t_block) * map->row_nb);
		if (!block_map[i])
		{
			free_block_map(block_map, i);
			return (0);
		}
		++i;
	}
	return (1);
}

int	init_block_map(t_canvas *canvas, t_map *map, t_list **lst)
{
	t_block	**block_map;

	block_map = malloc(sizeof(t_block *) * map->line_nb);
	if (!block_map || !create_2d_tab(map, block_map))
		return (0);
	map->block_map = block_map;
	if (!fill_map(canvas, map, block_map, lst) || !check_map(map, block_map, 0, 0))
	{
		printf("error map configuration\n");
		return (0);
	}
	return (1);
}

t_map	*create_map(t_canvas *canvas, char *file_name)
{
	t_map	*new_map;
	t_list	*lst;

	new_map = init_map();
	if (!new_map)
		return (NULL);
	lst = loading_file(canvas->mlx, new_map, file_name);
	if (!lst)
	{
		destroy_map(canvas->mlx, new_map);
		return (NULL);
	}
	new_map->line_nb = ft_lstsize(lst);
	if (!init_block_map(canvas, new_map, &lst))
	{
		destroy_map(canvas->mlx, new_map);
		while (lst)
			ft_lstpop(&lst);
		return (NULL);
	}
	return (new_map);
}
 