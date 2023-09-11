
#include "../../includes/loading.h"

char	**switch_face(t_map *map, char **face, int num_face)
{
	if (num_face == 0)
	{
		*face = "NO";
		return (&map->NO_path);	
	}
	else if (num_face == 1)
	{
		*face = "SO";
		return (&map->SO_path);
	}
	else if (num_face == 2)
	{
		*face = "WE";
		return (&map->WE_path);
	}
	else
	{
		*face = "EA";
		return (&map->EA_path);
	}
}

int	loading_texture(char **map_face, char *line, char *face)
{
	int fd_test;
	size_t size;
	
	size = ft_strlen(line);
	line[size - 1] = '\0';
	// trim avant id
	line = trim_space(line, 0);
	if (ft_strncmp(line, face, 2) == 0)
	{
		// trim entre id et path
		line = trim_space(line, 2);
		if ((fd_test = open(line, O_RDONLY)) == -1)
		{
			perror("La texture n'existe pas");
			return (0);
		}
		close(fd_test);
		*map_face = line;
		return (1);
	}
	return (0);
}

int run_loading_texture(t_map *map, int num_face, int map_fd)
{
	char *line;
	char *face;
	char **map_face;

	line = trim_backspace(map_fd);
	if (line)
	{
		map_face = switch_face(map, &face, num_face);
		if (loading_texture(map_face, line, face))
			return (1);
	}
	return (0);
}
