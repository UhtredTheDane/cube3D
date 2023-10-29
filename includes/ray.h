/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:04:31 by agengemb          #+#    #+#             */
/*   Updated: 2023/10/29 14:04:34 by agengemb         ###   ########.fr       */
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
