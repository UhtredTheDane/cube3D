/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:15:54 by agengemb          #+#    #+#             */
/*   Updated: 2023/09/07 21:24:52 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

///usr/include/X11/X.h

char *create_wrapper(size_t row_nb)
{
	char *wrapper;
	size_t	i;

	wrapper = malloc(sizeof(char) * row_nb + 1);
	if (!wrapper)
		return (NULL);
	i = 0;
	while (i < row_nb)
	{
		wrapper[i] = ' ';
		++i;
	}
	wrapper[i] = '\0';
	return (wrapper);
}

t_list	*load_map_in_lst(int map_fd, size_t *row_nb)
{
	char	*line;
	t_list	*lst;
	t_list	*elem;
    size_t  size_line;
	char *wrapper1;
	char *wrapper2;
	char *line_ok;
	line = "";
	lst = NULL;
	while (line != NULL)
	{
		line = get_next_line(map_fd);
		if (line != NULL)
		{
            		size_line = ft_strlen(line);
			line_ok = malloc(sizeof(char) * (size_line + 2));
			if (!line_ok)
				return (NULL);
			line_ok[0] = ' ';
			ft_strlcat(line_ok + 1, line, size_line + 1);
			line_ok[size_line] = ' ';
			if (size_line > *row_nb)
                *row_nb = size_line;
			elem = ft_lstnew(line_ok);
			if (elem)
				ft_lstadd_back(&lst, elem);
		}
	}
	wrapper1 = create_wrapper(*row_nb);
	wrapper2 = create_wrapper(*row_nb);
	t_list *wrap1 = ft_lstnew(wrapper1);
	t_list *wrap2 = ft_lstnew(wrapper2);
	ft_lstadd_front(&lst, wrap1);
	ft_lstadd_back(&lst, wrap2);

	return (lst);
}

t_list *read_map(char *file_name, size_t *row_nb)
{
    t_list *lst;
    int map_fd;

    if ((map_fd = open(file_name, O_RDONLY)) == -1)
    {
            perror("Can't open map file");
            return (NULL);
    }
    lst = load_map_in_lst(map_fd, row_nb);
    if (!lst)
    {
        printf("Can't load map\n");
        return (NULL);
    }
    close(map_fd);
    return (lst);  
}

t_map	*init_map(size_t line_nb, size_t row_nb)
{
	t_map	*new_map;

	new_map = malloc(sizeof(t_map));
	if (!new_map)
		return (NULL);
	new_map->line_nb = line_nb;
	new_map->row_nb = row_nb;
	new_map->player = 0;
	return (new_map);
}

int	create_2d_tab(t_map *map, t_block **block_map)
{
	size_t	i;

	i = 0;
	while (i < map->line_nb)
	{
		block_map[i] = malloc(sizeof(t_block) * map->row_nb - 1);
		if (!block_map[i])
		{
			free_block_map(block_map, i);
			return (0);
		}
		++i;
	}
	return (1);
}

int	check_block(void *mlx, t_map *map, char symbol)
{
	if (mlx == NULL)
		printf("error");

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

void	init_block(t_block *block, char symbol)
{
	block->type = symbol;
}

int	fill_map(void *mlx, t_map *map, t_block **block_map, t_list *list)
{
	char	*line;
	size_t	pos[2];

	mlx = (void *) mlx;
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

int	check_path(t_map *map, t_block **block_map, int i_start, int j_start)
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
		while (j < map->row_nb)
		{
			if (!check_remaining(map, copy_map, i, j))
				return (0);
			++j;
		}
		++i;
	}
	free_block_map(copy_map, map->line_nb);
	return (1);
}

void	rec_fill(t_map *map, t_block **block_map, int i, int j)
{
	block_map[i][j].type = 'V';
	if (i > 0 && block_map[i - 1][j].type != 'V' && block_map[i - 1][j].type != '1')
		rec_fill(map, block_map, i - 1, j);
	if (i < (int)map->line_nb - 1 && block_map[i + 1][j].type != 'V' && block_map[i + 1][j].type != '1')
		rec_fill(map, block_map, i + 1, j);
	if (j < (int)map->row_nb - 1 && block_map[i][j + 1].type != 'V' && block_map[i][j + 1].type != '1')
		rec_fill(map, block_map, i, j + 1);
	if (j > 0 && block_map[i][j - 1].type != 'V' && block_map[i][j - 1].type != '1')
		rec_fill(map, block_map, i, j - 1);
}

int	check_remaining(t_map *map, t_block **copy_map, size_t i, size_t j)
{
	if (copy_map[i][j].type != 'V'  && copy_map[i][j].type != '1' && copy_map[i][j].type != ' ')
	{
		free_block_map(copy_map, map->line_nb);
		printf("copy_map: %c\n", copy_map[i][j].type);
		printf("Error\nIl n'existe pas de chemin valide\n");
		return (0);
	}
	return (1);
}

t_block **copy(t_map *map, t_block **block_map)
{
	size_t i;
	size_t j;
	t_block **back;

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
		while (j < map->row_nb)
		{
			if (copy_map[i][j].type == 'E' || copy_map[i][j].type == 'W' || copy_map[i][j].type == 'S' || copy_map[i][j].type == 'N')
			{
				free_block_map(copy_map, map->line_nb);
				return (1);
			}
			++j;
		}
		++i;
	}
	free_block_map(copy_map, map->line_nb);
	return (0);
}

int	init_block_map(void *mlx, t_map *map, t_list *lst)
{
	t_block	**block_map;

	if (mlx == NULL)
		printf("erreur");
	block_map = malloc(sizeof(t_block *) * map->line_nb);
	if (!block_map || !create_2d_tab(map, block_map))
		return (0);
	map->block_map = block_map;
	if (!fill_map(mlx, map, block_map, lst) || !check_map(map, block_map, 0, 0))
	{
		free_block_map(block_map, map->line_nb);
		return (0);
	}
	return (1);
}

t_map	*create_map(void *mlx, t_list *lst, size_t line_nb, size_t row_nb)
{
	t_map	*new_map;
	
	new_map = init_map(line_nb, row_nb);
	if (!new_map)
		return (NULL);
	if (!init_block_map(mlx, new_map, lst))
	{
		free(new_map);
		return (NULL);
	}
	return (new_map);
}
