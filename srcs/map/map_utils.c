/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:12:18 by anmande           #+#    #+#             */
/*   Updated: 2023/11/03 15:30:41 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map/map.h"

void	set_data_pose_player(t_canvas *canvas, size_t i, size_t j)
{
	canvas->player->x = j + 0.5;
	canvas->player->y = i + 0.5;
	canvas->player->dir_x = 0;
	canvas->player->dir_y = 0;
	canvas->player->plane_x = 0.;
	canvas->player->plane_y = 0.;
}

void	init_pos_player(t_canvas *canvas, size_t i, size_t j, char dir)
{
	set_data_pose_player(canvas, i, j);
	if (dir == 'N')
	{
		canvas->player->dir_y = -1;
		canvas->player->plane_x = 0.66;
	}
	else if (dir == 'S')
	{
		canvas->player->dir_y = 1;
		canvas->player->plane_x = -0.66;
	}
	else if (dir == 'E')
	{
		canvas->player->dir_x = 1;
		canvas->player->plane_y = 0.66;
	}
	else
	{
		canvas->player->dir_x = -1.;
		canvas->player->plane_y = -0.66;
	}
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

int	init_block_map(t_canvas *canvas, t_map *map, t_list **lst)
{
	t_block	**block_map;

	block_map = malloc(sizeof(t_block *) * map->line_nb);
	if (!block_map || !create_2d_tab(map, block_map))
		return (0);
	map->block_map = block_map;
	if (!fill_map(canvas, map, block_map, lst) || \
	!check_map(map, block_map, 0, 0))
	{
		printf("error map configuration\n");
		return (0);
	}
	return (1);
}
