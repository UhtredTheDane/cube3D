
#include "../../includes/loading.h"

t_img	**switch_face(t_map *map, char **face, int num_face)
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

int loading_texture(void *mlx, t_img **map_face, char *line)
{
	size_t size;
	
	size = ft_strlen(line);
	line[size - 1] = '\0';
	line = trim_space(line, 0);
	if (*map_face != NULL)
	{
		free(line);
		return (0);
	}
	*map_face = init_img(mlx, line);
	if (!*map_face)
		return (0);
	return (1);
}

int run_loading_texture(void *mlx, t_map *map, char *line, int num_face)
{
	char *face;
	t_img **map_face;
	
	line = trim_space(line, 3);
	if (line)
	{
		map_face = switch_face(map, &face, num_face);
		if (loading_texture(mlx, map_face, line))
			return (1);
	}
	return (0);
}  
