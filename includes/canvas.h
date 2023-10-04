#ifndef CANVAS_H
# define CANVAS_H

# include <stdlib.h>
# include <stddef.h>
# include "../mlx_linux/mlx.h"
# include "map/map.h"
# include "../libft/libft.h"
# include "map/checking.h"

typedef struct s_map	t_map;

typedef struct s_canvas
{
	void	*mlx;
<<<<<<< Updated upstream
	void	*window;	
=======
	void	*window;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		width;
	int		color;
	int		height;
	char	*path;
	int		line_length;
	int		endian;
>>>>>>> Stashed changes
	t_map	*map;
}			t_canvas;

t_canvas	*create_canvas(char *file_name);
void	destroy_canvas(t_canvas *canvas);
#endif
