
#include "libft.h"

t_dlist			*ft_dlst_push_back(t_dlist *list, t_node *new)
{
	if (list != NULL)
	{
		if (list->last == NULL)
		{
			new->prev = NULL;
			list->first = new;
			list->last = new;
		}
		else
		{
			list->last->next = new;
			new->prev = list->last;
			list->last = new;
		}
		list->lenght++;
	}
	return (list);
}
