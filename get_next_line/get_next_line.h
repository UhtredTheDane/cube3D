/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:43:23 by agengemb          #+#    #+#             */
/*   Updated: 2023/09/07 02:24:53 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_lst
{
	char			content;
	struct s_lst	*next;

}			t_lst;

char	*get_next_line(int fd);
char	*create_buffer(int fd);
int		is_contains_nl(char *str);
t_lst	*lstnew(char content);
void	push_back(t_lst **lst, t_lst *new);
void	pop_front(t_lst **lst);
t_lst	*lstlast(t_lst *lst);
int		lstsize(t_lst *list);
t_lst	*create_stash(char *buffer, t_lst *stash, int octets_read);
char	*create_line(t_lst **stash);
#endif
