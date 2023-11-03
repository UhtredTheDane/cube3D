/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:04:31 by agengemb          #+#    #+#             */
/*   Updated: 2023/11/02 15:33:54 by anmande          ###   ########.fr       */
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
	int lineHeight;
	int drawStart;
	int drawEnd;
	double dw;
}		t_ray;

#endif
