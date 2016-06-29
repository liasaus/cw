
#include "libft.h"

int		ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return (0);
	if (!(*alst))
	{
		*alst = new;
		return (1);
	}
	temp = *alst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return (1);
}
