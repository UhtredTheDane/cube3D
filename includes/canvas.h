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
# include "player.h"

typedef struct s_map	t_map;
typedef struct s_player	t_player;

typedef struct s_canvas
{
	void		*mlx;
	void		*window;
<<<<<<< HEAD
=======
	void		*window2;
>>>>>>> amande
	void		*img;
	char		*addr;
	int			bpp;
	int			endian;
	int			line_len;
	char		*path;
	t_map		*map;
	int			fd;
<<<<<<< HEAD
=======
	double		dist;
>>>>>>> amande
	t_player	*player;
}			t_canvas;

t_canvas	*create_canvas(char *file_name);
void		destroy_canvas(t_canvas *canvas);
#endif
