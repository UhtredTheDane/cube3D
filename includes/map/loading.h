/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 23:24:25 by agengemb          #+#    #+#             */
/*   Updated: 2023/09/07 23:39:59 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOADING_H
# define LOADING_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../../libft/libft.h"
# include "../../get_next_line/get_next_line.h"


t_list *read_map(char *file_name, size_t *row_nb);
t_list	*load_map_in_lst(int map_fd, size_t *row_nb);
t_list *load_line(t_list **lst, char *line, size_t *row_nb);
void	add_wrappers(t_list **lst, size_t row_nb);
char	*create_wrapper(size_t row_nb);


#endif
