
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