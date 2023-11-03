/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:04:31 by agengemb          #+#    #+#             */
/*   Updated: 2023/11/03 18:22:51 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H

# define RAY_H

# include "main.h"

typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
	double	sidedist_x;
	double	sidedisty;
	double	deltadist_x;
	double	deltadisty;
	int		n_l_hit;
	int		side;
	int		row_hit;
	int		stepx;
	int		stepy;
	int		lineheight;
	int		drawstart;
	int		drawend;
	double	dw;
}		t_ray;

#endif
