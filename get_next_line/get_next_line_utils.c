/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:42:45 by agengemb          #+#    #+#             */
/*   Updated: 2023/09/07 02:24:02 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_lst	*lstnew(char content)
{
	t_lst	*res;

	res = malloc(sizeof(t_lst));
	if (!res)
		return (NULL);
	res->content = content;
	res->next = NULL;
	return (res);
}

void	push_back(t_lst **lst, t_lst *new)
{
	t_lst	*elem;

	if (lst && new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			elem = *lst;
			while (elem->next != NULL)
				elem = elem->next;
			elem->next = new;
		}
	}
}

void	pop_front(t_lst **lst)
{
	t_lst	*elem;

	if (lst && *lst)
	{
		elem = *lst;
		*lst = (*lst)->next;
		free(elem);
	}
}

t_lst	*lstlast(t_lst *lst)
{	
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

int	lstsize(t_lst *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
