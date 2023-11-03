/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:15:54 by agengemb          #+#    #+#             */
/*   Updated: 2023/11/03 15:32:21 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map/checking.h"

///usr/include/X11/X.h

int	check_block(void *mlx, t_map *map, char symbol)
{
	mlx = (void *) mlx;
	if (symbol == '1' || symbol == '0' || symbol == ' ')
		return (1);
	else if (symbol == 'N' || symbol == 'S' || symbol == 'E' || symbol == 'W')
	{
		if (map->player)
			return (0);
		map->player = 1;
		return (1);
	}
	printf("Error\nUn blocks de la map n'est pas valide\n");
	return (0);
}

void	rec_fill(t_map *map, t_block **block_map, int i, int j)
{
	block_map[i][j].type = 'V';
	if (i > 0 && block_map[i - 1][j].type != 'V' && \
	block_map[i - 1][j].type != '1')
		rec_fill(map, block_map, i - 1, j);
	if (i < (int)map->line_nb - 1 && \
	block_map[i + 1][j].type != 'V' && block_map[i + 1][j].type != '1')
		rec_fill(map, block_map, i + 1, j);
	if (j < (int)map->row_nb - 1 && \
	block_map[i][j + 1].type != 'V' && block_map[i][j + 1].type != '1')
		rec_fill(map, block_map, i, j + 1);
	if (j > 0 && block_map[i][j - 1].type != 'V' && \
	block_map[i][j - 1].type != '1')
		rec_fill(map, block_map, i, j - 1);
}

t_block	**copy(t_map *map, t_block **block_map)
{
	size_t	i;
	size_t	j;
	t_block	**back;

	back = malloc(sizeof(t_block *) * map->line_nb);
	if (!back)
		return (NULL);
	i = 0;
	while (i < map->line_nb)
	{
		back[i] = malloc(sizeof(t_block) * map->row_nb);
		if (!back[i])
		{
			free_block_map(back, i);
			return (NULL);
		}
		j = 0;
		while (j < map->row_nb)
		{
			back[i][j] = block_map[i][j];
			++j;
		}
		++i;
	}
	return (back);
}

int	check_map(t_map *map, t_block **block_map, int i_start, int j_start)
{
	t_block	**copy_map;
	size_t	i;
	size_t	j;

	copy_map = copy(map, block_map);
	if (!copy_map)
		return (0);
	rec_fill(map, copy_map, i_start, j_start);
	i = 0;
	while (i < map->line_nb)
	{
		j = 0;
		while (j++ < map->row_nb)
		{
			if (copy_map[i][j].type == 'E' || copy_map[i][j].type == 'W' || \
			copy_map[i][j].type == 'S' || copy_map[i][j].type == 'N')
			{
				free_block_map(copy_map, map->line_nb);
				return (1);
			}
		}
		++i;
	}
	free_block_map(copy_map, map->line_nb);
	return (0);
}
