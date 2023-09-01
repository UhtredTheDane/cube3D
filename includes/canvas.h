#ifndef CANVAS_H
# define CANVAS_H

# include <stdlib.h>
# include <stddef.h>
# include "../mlx_linux/mlx.h"
# include "map.h"
# include "queue.h"
# include "parsing.h"

typedef struct s_map	t_map;

typedef struct s_canvas
{
	void	*mlx;
	void	*window;	
	t_map	*map;
}			t_canvas;

t_canvas	*create_canvas(t_queue *queue, size_t line_nb, size_t row_nb);

#endif
