
#include "libft.h"

size_t	ft_lstlen(t_list *lst)
{
	size_t i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
