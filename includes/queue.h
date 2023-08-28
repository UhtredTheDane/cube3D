/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:36:44 by agengemb          #+#    #+#             */
/*   Updated: 2023/08/28 10:36:45 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include <stdlib.h>

typedef struct s_queue
{
	char			*content;
	struct s_queue	*next;
}			t_queue;

t_queue	*ft_queuenew(char *content);
void	queue_add(t_queue **queue, t_queue *new);
void	queue_pop(t_queue **queue);
int		ft_queuesize(t_queue *queue);
void	free_queue(t_queue *queue);
#endif
