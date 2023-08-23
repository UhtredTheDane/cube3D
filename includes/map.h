#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

typedef struct s_map
{
	size_t		row_nb;
	size_t		line_nb;
	t_block		**block_map;
}	t_map;

#endif