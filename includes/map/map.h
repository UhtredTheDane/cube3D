#ifndef MAP_H
# define MAP_H
 
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include "../block.h"
# include "checking.h"
# include "../loading.h"
# include "../img.h"

typedef struct s_map
{
	int player;
	size_t		row_nb;
	size_t		line_nb;
	t_img		*NO_path;
	t_img		*SO_path;
	t_img		*WE_path;
	t_img		*EA_path;
	int		floor_color;
	int		ceiling_color;
	t_block		**block_map;
}	t_map;

t_map *init_map(void);
int create_2D_tab(t_map *map, t_block **block_map);
int fill_map(void *mlx, t_map *map, t_block **block_map, t_list *list);
int init_block_map(void *mlx, t_map *map, t_list *list);
t_map	*create_map(void *mlx, char *file_name);

#endif
