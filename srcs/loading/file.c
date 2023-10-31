/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 23:25:28 by agengemb          #+#    #+#             */
/*   Updated: 2023/10/31 18:26:40 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loading.h"

int	get_textures_colors(void *mlx, t_map *map, int map_fd)
{
	char	*line;

	line = trim_backspace(map_fd);
	if (!line)
		return (0);
	line = trim_space(line, 0);
	if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		return (loading_color(map, line, line[0]));
	else if (ft_strncmp(line, "NO ", 3) == 0)
		return (run_loading_texture(mlx, map, line, 0));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (run_loading_texture(mlx, map, line, 1));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (run_loading_texture(mlx, map, line, 2));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (run_loading_texture(mlx, map, line, 3));
	free (line);
	return (0);
}

t_list	*get_map(t_map *map, int map_fd)
{
	t_list	*lst;

	lst = loading_map(map_fd, &map->row_nb);
	close(map_fd);
	if (!lst)
	{
		printf("Can't load map\n");
	}
	return (lst);
}

t_list	*loading_file(void *mlx, t_map *map, char *file_name)
{
	int	map_fd;
	int	i;

	i = 0;
	map_fd = open(file_name, O_RDONLY);
	if (map_fd < 0)
	{
		perror("Can't open map file");
		return (NULL);
	}
	while (i++ < 6)
	{
		if (!get_textures_colors(mlx, map, map_fd))
		{
			printf("Erreur Chargement couleurs ou textures\n");
			close(map_fd);
			return (NULL);
		}
	}
	return (get_map(map, map_fd));
}
