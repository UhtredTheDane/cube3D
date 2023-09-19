#include "../includes/img.h"
#include <stdio.h>

t_img	*init_img(void *mlx, char *path)
{
	t_img	*new_img;

	mlx = (void *) mlx;
	new_img = malloc(sizeof(t_img));
	if (!new_img)
		return (NULL);
	new_img->path = path;
	new_img->img = mlx_xpm_file_to_image(mlx, new_img->path, &(new_img->width), &(new_img->height));
	if (!new_img->img)
	{
		free(new_img);
		return (NULL);
	}

	return (new_img);
}

void	free_img(void *mlx, t_img *img)
{
	mlx_destroy_image(mlx, img->img);
	free(img);
}