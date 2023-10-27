/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:30:19 by anmande           #+#    #+#             */
/*   Updated: 2023/10/27 16:30:21 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DATA_H
# define DATA_H

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_data;

#endif