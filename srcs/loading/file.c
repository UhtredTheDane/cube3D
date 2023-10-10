/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 23:25:28 by agengemb          #+#    #+#             */
/*   Updated: 2023/10/04 14:39:01 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loading.h"
/*
int get_textures(void *mlx, t_map *map, int map_fd)
{
    if (!run_loading_texture(mlx, map, 0, map_fd) ||  !run_loading_texture(mlx, map, 1, map_fd) || 
		!run_loading_texture(mlx, map, 2, map_fd) || !run_loading_texture(mlx, map, 3, map_fd))
	{
		printf("error loading texture\n");
		return (0);
	}
    return (1);
}*/
/*
int get_colors(t_map *map, int map_fd)
{
    if (!loading_color(map, "F", map_fd) || !loading_color(map, "C", map_fd))
	{
		printf("error loading color\n");
		return (0);
	}
    return (1);
}*/

int get_textures_colors(void *mlx, t_map *map, int map_fd)
{
    char *line;

    line = trim_backspace(map_fd);
    if (line)
    {
        line = trim_space(line, 0);
        if (ft_strncmp(line, "F ", 2) == 0)
        {
            if(!loading_color(map, line, 'F'))
                return (0);
        }
        else if (ft_strncmp(line, "C ", 2) == 0)
        {
            if(!loading_color(map, line, 'C'))
                return (0);
        }
        else if (ft_strncmp(line, "NO ", 3) == 0)
        {
            if (!run_loading_texture(mlx, map, line, 0))
                return (0);
        }
        else if (ft_strncmp(line, "SO ", 3) == 0)
        {
            if (!run_loading_texture(mlx, map, line, 1))
                return (0);
        }
        else if (ft_strncmp(line, "WE ", 3) == 0)
        {
            if (!run_loading_texture(mlx, map, line, 2))
                return (0);
        }
        else if (ft_strncmp(line, "EA ", 3) == 0)
        {
            if (!run_loading_texture(mlx, map, line, 3))
                return (0);
        }
        else
            return (0);
        return (1);
    }
    return (0);
}

t_list *get_map(t_map *map, int map_fd)
{
    t_list	*lst;

    lst = loading_map(map_fd, &map->row_nb);
    close(map_fd);
    if (!lst)
        printf("Can't load map\n");
    return (lst);
}
 
t_list *loading_file(void *mlx, t_map *map, char *file_name)
{
    int		map_fd;

    if ((map_fd = open(file_name, O_RDONLY)) == -1)
    {
            perror("Can't open map file");
            return (NULL);
    }
    for (int i = 0; i < 6; ++i)
    {
        if (!get_textures_colors(mlx, map, map_fd))
        {
            printf("Erreur Chargement couleurs ou textures\n");
            close(map_fd);
            return (NULL);
        }
    }
    /*if (!get_textures(mlx, map, map_fd) || !get_colors(map, map_fd))
    {
        close(map_fd);
        return (NULL);
    }*/
    return (get_map(map, map_fd));  
}
