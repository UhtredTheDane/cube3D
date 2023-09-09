/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 23:25:28 by agengemb          #+#    #+#             */
/*   Updated: 2023/09/10 00:38:20 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map/loading.h"

char	*create_wrapper(size_t row_nb)
{
	char	*wrapper;
	size_t	i;

	wrapper = malloc(sizeof(char) * (row_nb + 1));
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

void	add_wrappers(t_list **lst, size_t row_nb)
{
	char *wrapper1;
	char *wrapper2;
	t_list	*wrap1;
	t_list	*wrap2;
	// tester lst a null
	wrapper1 = create_wrapper(row_nb);
	wrapper2 = create_wrapper(row_nb);
	wrap1 = ft_lstnew(wrapper1);
	wrap2 = ft_lstnew(wrapper2);
	ft_lstadd_front(lst, wrap1);
	ft_lstadd_back(lst, wrap2);
}

t_list *load_line(t_list **lst, char *line, size_t *row_nb)
{
    	size_t  size_line;
	char	*line_ok;
	t_list	*elem;

	size_line = ft_strlen(line);
	line_ok = malloc(sizeof(char) * (size_line + 2));
	if (!line_ok)
		return (NULL);
	line_ok[0] = ' ';
	ft_strlcpy(line_ok + 1, line, size_line + 1);
	line_ok[size_line] = ' ';
	size_line = ft_strlen(line_ok);
	if (size_line > *row_nb)
		*row_nb = size_line;
	elem = ft_lstnew(line_ok);
	if (elem)
		ft_lstadd_back(lst, elem);
	return (*lst);
}

t_list	*load_map_in_lst(int map_fd, size_t *row_nb)
{
	char	*line;
	t_list	*lst;
	int i;

	lst = NULL;
	line = get_next_line(map_fd);
	while (ft_strncmp(line, "\n", 1) == 0)
	{
		free(line);
		line = get_next_line(map_fd);
	}
	i = 0;
	while (line != NULL)
	{
		if (i)
		{
			free(line);
			line = get_next_line(map_fd);
		}
		if (line)
		{
			lst = load_line(&lst, line, row_nb);
			if (!lst)
				return (NULL);
		}
		++i;
	}
	add_wrappers(&lst, *row_nb);
	return (lst);
}

int load_texture(t_map *map, int num_face, int map_fd)
{
	char *line;
	char *face;
	char **map_face;
	char *tempo_line;

	map = (t_map *) map;
	line = get_next_line(map_fd);
	while (ft_strncmp(line, "\n", 1) == 0)
	{
		free(line);
		line = get_next_line(map_fd);
	}
	if (line)
	{
		if (num_face == 0)
		{
			map_face = &map->NO_path;	
			face = "NO";
		}
		else if (num_face == 1)
		{
			map_face = &map->SO_path;
			face = "SO";
		}
		else if (num_face == 2)
		{
			map_face = &map->WE_path;
			face = "WE";
		}
		else
		{
			map_face = &map->EA_path;
			face = "EA";
		}

		size_t size = ft_strlen(line);
		line[size - 1] = '\0';

		// trim avant id
		tempo_line = ft_strtrim(line, " ");
		free(line);

		if (ft_strncmp(tempo_line, face, 2) == 0)
		{
			int fd_test;

			// trim entre id et path
			line = ft_strtrim(tempo_line + 2, " ");
			free(tempo_line);

			if ((fd_test = open(line, O_RDONLY)) == -1)
			{
				perror("La texture n'existe pas");
				return (0);
			}
			close(fd_test);

			*map_face = line;
			return (1);
		}
	}
	return (0);
}

int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int load_color(t_map *map, char *type, int map_fd)
{
	char *line;
	char *tempo_line;
	int *map_color;
	int r;
	int b;
	int g;
	int t = 0;

	line = get_next_line(map_fd);
	while (ft_strncmp(line, "\n", 1) == 0)
	{
		free(line);
		line = get_next_line(map_fd);
	}
	if (line)
	{
		if (type[0] == 'F')
		{
			map_color = &map->floor_color;
		}
		else
		{
			map_color = &map->ceiling_color;

		}
		// trim avant id
		tempo_line = ft_strtrim(line, " ");
		free(line);
		if (ft_strncmp(tempo_line, type, 1) == 0)
		{
			// trim entre id et path
			line = ft_strtrim(tempo_line + 1, " ");
			free(tempo_line);
			int i = 0;
			tempo_line = line;
			while (i < 3)
			{
				char *virgule;
				if (i == 0)
				{

					virgule = ft_strrchr(tempo_line, ',');
					*virgule = '\0';
					r = ft_atoi(tempo_line);
				}
				else if (i == 1)
				{
					virgule = ft_strrchr(tempo_line, ',');
					*virgule = '\0';
					g = ft_atoi(tempo_line);
				}
				else
				{	
					virgule = ft_strrchr(tempo_line, '\n');
					*virgule = '\0';
					b = ft_atoi(tempo_line);
				}
				*virgule = ',';
				tempo_line += virgule - tempo_line + 1;
				++i;
			}
			*map_color = create_trgb(t, r, g, b);
			return (1);
		}
	}
	return (0);
}

t_list *read_map(t_map *map, char *file_name)
{
    t_list	*lst;
    int		map_fd;

    map = (t_map *) map;
    if ((map_fd = open(file_name, O_RDONLY)) == -1)
    {
            perror("Can't open map file");
            return (NULL);
    }

//	if (load_texture(t_map *map, int num_face, int map_fd))
	if (!load_texture(map, 0, map_fd) ||  !load_texture(map, 1, map_fd) || !load_texture(map, 2, map_fd) || !load_texture(map, 3, map_fd))
	{
		printf("error loading texture\n");
		return (NULL);
	}
    lst = load_map_in_lst(map_fd, &(map->row_nb));
    if (!lst)
    {
        printf("Can't load map\n");
        return (NULL);
    }
    close(map_fd);
    return (lst);  
}
