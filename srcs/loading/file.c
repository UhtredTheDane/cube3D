/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 23:25:28 by agengemb          #+#    #+#             */
/*   Updated: 2023/09/10 19:41:15 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loading.h"

int get_textures(t_map *map, int map_fd)
{
    if (!run_loading_texture(map, 0, map_fd) ||  !run_loading_texture(map, 1, map_fd) || 
		!run_loading_texture(map, 2, map_fd) || !run_loading_texture(map, 3, map_fd))
	{
		printf("error loading texture\n");
		return (NULL);
	}
}

int get_colors(t_map *map, int map_fd)
{
    if (!loading_color(map, "F", map_fd) || !loading_color(map, "C", map_fd))
	{
		printf("error loading color\n");
		return (NULL);
	}
}

t_list *get_map(t_map *map, int map_fd)
{
    t_list	*lst;

    lst = loading_map(map_fd, &(map->row_nb));
    if (!lst)
        printf("Can't load map\n");
    close(map_fd);
    return (lst)
}

t_list *loading_file(t_map *map, char *file_name)
{
    int		map_fd;

    if ((map_fd = open(file_name, O_RDONLY)) == -1)
    {
            perror("Can't open map file");
            return (NULL);
    }
    if (!get_textures(t_map *map, int map_fd) || !get_colors(map, map_fd))
    {
        return (NULL);
    }
    return (get_map(map, map_fd));  
}
