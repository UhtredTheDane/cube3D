/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
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
	new_map->line_nb = 0;
	new_map->row_nb = 0;
	new_map->player = 0;
	new_map->NO_path = NULL;
	new_map->SO_path = NULL;
	new_map->WE_path = NULL;
	new_map->EA_path = NULL;
	return (new_map);
}

int	fill_map(void *mlx, t_map *map, t_block **block_map, t_list *list)
{
	char	*line;
	size_t	pos[2];

	pos[0] = 0;
	while (pos[0] < map->line_nb)
	{
		line = list->content;
		pos[1] = 0;
		while (pos[1] < map->row_nb)
		{
			if (!check_block(mlx, map, line[pos[1]]))
			{
				ft_lstclear(&list, free);
				return (0);
			}
			init_block(&block_map[pos[0]][pos[1]], line[pos[1]]);
			++pos[1];
		}
		ft_lstpop(&list);
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

int	init_block_map(void *mlx, t_map *map, t_list *lst)
{
	t_block	**block_map;

	block_map = malloc(sizeof(t_block *) * map->line_nb);
	if (!block_map || !create_2d_tab(map, block_map))
		return (0);
	map->block_map = block_map;


	if (!fill_map(mlx, map, block_map, lst) || !check_map(map, block_map, 0, 0))
	{
		printf("error map configuration\n");
		//free_block_map(block_map, map->line_nb);
		return (0);
	}
	return (1);
}

t_map	*create_map(void *mlx, char *file_name)
{
	t_map	*new_map;
	t_list	*lst;

	new_map = init_map();
	if (!new_map)
		return (NULL);
	lst = loading_file(mlx, new_map, file_name);
	if (!lst)
	{
		//destroy_map(mlx, new_map);
		free(new_map);
		return (NULL);
	}
	new_map->line_nb = ft_lstsize(lst);
	if (!init_block_map(mlx, new_map, lst))
	{
		/*destroy_map(mlx, new_map);
		while (lst)
			ft_lstpop(&lst);
		free(new_map);*/
		return (NULL);
	}
	return (new_map);
}
