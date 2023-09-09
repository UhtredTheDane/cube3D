#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include "../block.h"
# include "parsing.h"

typedef struct s_map
{
	int player;
	size_t		row_nb;
	size_t		line_nb;
	char		*NO_path;
	char		*SO_path;
	char		*WE_path;
	char		*EA_path;
	int		floor_color;
	int		ceiling_color;
	t_block		**block_map;
}	t_map;

t_map *init_map(void);
int create_2D_tab(t_map *map, t_block **block_map);
void init_block(t_block *block, char symbol);
int fill_map(void *mlx, t_map *map, t_block **block_map, t_list *list);
int init_block_map(void *mlx, t_map *map, t_list *list);
t_map	*create_map(void *mlx, char *file_name);

#endif
