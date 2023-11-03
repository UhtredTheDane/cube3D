/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:04:02 by agengemb          #+#    #+#             */
/*   Updated: 2023/11/02 15:33:30 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		linlgth;
	int		end;
}				t_data;

#endif
