/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:21:13 by anmande           #+#    #+#             */
/*   Updated: 2023/11/03 18:21:21 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H

# include <stdlib.h>
# include <stddef.h>
# include "../mlx_linux/mlx.h"

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
	char	*path;
}		t_img;

t_img	*init_img(void *mlx, char *path);
void	free_img(void *mlx, t_img *img);

#endif