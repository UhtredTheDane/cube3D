#ifndef CANVAS_H
# define CANVAS_H
# define Y_LEN		1200
# define X_LEN		(Y_LEN)

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
	void	*window;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		width;
	int		height;
	char	*path;
	t_map	*map;
}			t_canvas;

t_canvas	*create_canvas(char *file_name);
void	destroy_canvas(t_canvas *canvas);
#endif
