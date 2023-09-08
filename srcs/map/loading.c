/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 23:25:28 by agengemb          #+#    #+#             */
/*   Updated: 2023/09/09 00:19:27 by agengemb         ###   ########.fr       */
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
	ft_strlcat(line_ok + 1, line, size_line + 1);
	line_ok[size_line] = ' ';
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
	
	lst = NULL;
	line = get_next_line(map_fd);
	while (ft_strncmp(line, "\n", 1) == 0)
		line = get_next_line(map_fd);
	while (line != NULL)
	{
		line = get_next_line(map_fd);
		if (line)	
		{
			lst = load_line(&lst, line, row_nb);
			if (!lst)
				return (NULL);
		}
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

	line = get_next_line(map_fd);
	while (ft_strncmp(line, "\n", 1) == 0)
		line = get_next_line(map_fd);
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
			printf("tempo: %s\n", line);
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
