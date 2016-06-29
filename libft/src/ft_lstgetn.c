
#include "libft.h"

t_list	*ft_lstgetn(t_list **lst, int n)
{
	while (n)
	{
		(*lst) = (*lst)->next;
		n--;
	}
	return (*(lst));
}
