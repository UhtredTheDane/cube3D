#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include "block.h"

typedef struct s_map
{
	int player;
	size_t		row_nb;
	size_t		line_nb;
	t_block		**block_map;
}	t_map;

#endif