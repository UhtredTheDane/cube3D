#include "get_next_line.h"

void	pop_char(t_list **lst)
{
	t_list	*elem;

	if (lst && *lst)
	{
		elem = *lst;
		*lst = (*lst)->next;
		free(elem);
	}
}