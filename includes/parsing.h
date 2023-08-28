/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:15:42 by agengemb          #+#    #+#             */
/*   Updated: 2023/08/21 18:15:43 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "queue.h"
# include "map.h"

t_queue *read_map(char *file_name);
t_queue	*load_map_in_queue(int map_fd, size_t *row_nb);

#endif
