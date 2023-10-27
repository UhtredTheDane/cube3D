/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:29:31 by anmande           #+#    #+#             */
/*   Updated: 2023/10/27 16:31:48 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H

# define RAY_H

# include "main.h"

typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
    double sidedist_x;
	double sidedisty;
    double deltadist_x;
	double deltadisty;
    int row_hit;
    int n_l_hit;
	int stepx;
	int stepY;
	int side;
}		t_ray;

#endif