/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:12:20 by anmande           #+#    #+#             */
/*   Updated: 2023/11/03 18:12:23 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpop(t_list **list)
{
	t_list	*elem;

	elem = NULL;
	if (list && *list)
	{
		elem = (*list)->next;
		if (*(char *)(*list)->content)
			free((*list)->content);
		free(*list);
		*list = elem;
	}
}
