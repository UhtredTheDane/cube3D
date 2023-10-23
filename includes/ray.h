#ifndef RAY_H
# define RAY_H

typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
    double sideDistX;
	double sideDistY;
    double deltaDistX;
	double deltaDistY;
    int num_row_hit;
    int num_line_hit;
	int stepX;
	int stepY;
	int side;
}		t_ray;

#endif